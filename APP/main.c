#include "Services/bit_math.h"
#include "MCAL/GPIO/GPIO_interface.h"
#include "MCAL/UART/UART_interface.h"
#include "MCAL/TIMER0/TIMER0_interface.h"
#include "MCAL/TIMER0/TIMER0_private.h"
#include "MCAL/SPI/SPI_interface.h"
#include "MCAL/PWM/PWM_interface.h"
#include "MCAL/I2C/I2C_interface.h"
#include "MCAL/EXTI/EXTI_interface.h"
#include "MCAL/EXTI/EXTI_private.h"
#include "MCAL/ADC/ADC_interface.h"

/* ?? shared state ????????????????????????????????????????????????????????? */
volatile unsigned char timer_tick = 0;
volatile unsigned char exti_flag  = 0;

/* ?? isr (mikroC syntax: no name after 'interrupt') ???????????????????? */
void interrupt()
{
    if (GET_BIT(INTCON_REG, TMR0IF_BIT))
    {
        CLR_BIT(INTCON_REG, TMR0IF_BIT);
        timer_tick = 1;
    }

    if (GET_BIT(INTCON_REG, INTF_BIT))
    {
        CLR_BIT(INTCON_REG, INTF_BIT);
        exti_flag = 1;
    }
}


static void run_adc_uart(void)
{
    unsigned int  val;
    unsigned char buf[6];

    val    = ADC_Read(0);
    buf[0] = '0' + (unsigned char)((val / 1000) % 10);
    buf[1] = '0' + (unsigned char)((val / 100)  % 10);
    buf[2] = '0' + (unsigned char)((val / 10)   % 10);
    buf[3] = '0' + (unsigned char)( val          % 10);
    buf[4] = '\r';
    buf[5] = '\n';

    UART_SendByte(buf[0]);
    UART_SendByte(buf[1]);
    UART_SendByte(buf[2]);
    UART_SendByte(buf[3]);
    UART_SendByte(buf[4]);
    UART_SendByte(buf[5]);
}

static void run_spi(void)
{
    unsigned char resp = SPI_Transfer(0xAB);
    UART_SendByte(resp);
}

static void run_i2c(void)
{
    unsigned char val;

    /* write 0x55 to eeprom address 0x00 */
    I2C_Start();
    I2C_Write(0xA0);
    I2C_Write(0x00);
    I2C_Write(0x55);
    I2C_Stop();

    /* read back */
    I2C_Start();
    I2C_Write(0xA0);
    I2C_Write(0x00);
    I2C_Start();
    I2C_Write(0xA1);
    val = I2C_Read(I2C_NACK);
    I2C_Stop();

    UART_SendByte(val);
}

void main()
{
    unsigned int pwm_duty = 0;

    GPIO_SetPinDirection(GPIO_PORTB, GPIO_PIN0, GPIO_INPUT);
    GPIO_SetPinDirection(GPIO_PORTB, GPIO_PIN1, GPIO_OUTPUT);
    GPIO_WritePin(GPIO_PORTB, GPIO_PIN1, GPIO_LOW);

    UART_Init();
    TIMER0_Init();
    ADC_Init();
    SPI_Init();
    I2C_Init();
    PWM_Init();

    EXTI_Init(EXTI_RISING_EDGE);
    EXTI_Enable();

    TIMER0_Start();

    UART_SendString("system ready\r\n");

    while (1)
    {
        while (!timer_tick);
        timer_tick = 0;

        run_adc_uart();

        pwm_duty = (pwm_duty + 32) & 0x03FF;
        PWM_SetDuty(pwm_duty);

        GPIO_TogglePin(GPIO_PORTB, GPIO_PIN1);

        if (exti_flag)
        {
            exti_flag = 0;
            UART_SendString("btn\r\n");
            run_spi();
            run_i2c();
        }
    }
}