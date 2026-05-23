#include <xc.h>

#include "../SERVICES/STD_TYPES.h"
#include "../SERVICES/DELAY.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/ADC/ADC_interface.h"
#include "../MCAL/USART/USART_Interface.h"
#include "../MCAL/TIMER_0/TIMER_0_Interface.h"
#include "../MCAL/TIMER_1/TIMER_1_interface.h"
#include "../MCAL/I2C/I2C_interface.h"
#include "../MCAL/PWM/PWM_interface.h"
#include "../MCAL/EXT_INT/EXT_INT_Interface.h"

static volatile u8 g_timer0_tick = 0U;
static volatile u8 g_ext_event = 0U;

static void Timer0_Callback(void)
{
    g_timer0_tick = 1U;
}

static void ExternalInterrupt_Callback(void)
{
    g_ext_event = 1U;
}

static void Application_Init(void)
{
    GPIO_Init();

    UART_TX_Init();
    UART_RX_Init();
    UART_SendString("MCAL self-test start\r\n");

    GPIO_SetPinDirection(GPIO_PORTB, GPIO_PIN0, GPIO_OUTPUT);
    GPIO_SetPinDirection(GPIO_PORTB, GPIO_PIN1, GPIO_OUTPUT);
    GPIO_SetPinDirection(GPIO_PORTA, GPIO_PIN0, GPIO_INPUT);

    ADC_Init();

    TIMER_0_Init();
    TIMER_0_SetCallback(Timer0_Callback);
    TIMER_0_Enable();

    TIMER1_Init();

    I2C_Master_Init(100000UL);

    PWM_Init(PWM_CHANNEL_1, 20000U);
    PWM_SetDutyCycle(PWM_CHANNEL_1, 50U);

    EXT_INT_Init();
    EXT_INT_SetEdge(falling_edge);
    EXT_INT_SetCallback(ExternalInterrupt_Callback);
    EXT_INT_Enable();

    UART_SendString("Init done\r\n");
}

static void I2C_Bus_Ping(void)
{
    I2C_Master_Start();
    I2C_Master_Stop();
}

static void Application_Run(void)
{
    u16 adcValue;

    while (1)
    {
        GPIO_SetPinValue(GPIO_PORTB, GPIO_PIN0, GPIO_HIGH);
        DELAY_ms(200);
        GPIO_SetPinValue(GPIO_PORTB, GPIO_PIN0, GPIO_LOW);
        DELAY_ms(200);

        adcValue = ADC_Read(ADC_CHANNEL_0);
        UART_SendString("ADC0=");
        UART_SendUInt(adcValue);
        UART_SendString("\r\n");

        if (g_timer0_tick)
        {
            g_timer0_tick = 0U;
            GPIO_SetPinValue(GPIO_PORTB, GPIO_PIN1, GPIO_HIGH);
            DELAY_ms(25);
            GPIO_SetPinValue(GPIO_PORTB, GPIO_PIN1, GPIO_LOW);
        }

        if (g_ext_event)
        {
            g_ext_event = 0U;
            UART_SendString("EXT_INT\r\n");
        }

        TIMER1_Clear();
        TIMER1_Start();
        DELAY_ms(10);
        TIMER1_Stop();
        UART_SendString("T1=");
        UART_SendUInt(TIMER1_GetCount());
        UART_SendString("\r\n");

        I2C_Bus_Ping();
        UART_SendString("I2C OK\r\n");

        PWM_SetDutyCycle(PWM_CHANNEL_1, 25U);
        DELAY_ms(100);
        PWM_SetDutyCycle(PWM_CHANNEL_1, 75U);
        DELAY_ms(100);
    }
}

int main(void)
{
    Application_Init();
    Application_Run();
    return 0;
}
