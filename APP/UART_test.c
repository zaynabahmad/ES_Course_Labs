#include "../HAL/LED/LED_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/EXT_INT/EXT_INT_interface.h"
#include "../MCAL/TIMER_0/TIMER_0_interface.h"
#include "../MCAL/ADC/ADC_interface.h"
#include "../MCAL/PWM/PWM_interface.h"
#include "../MCAL/USART/USART_interface.h"
#include "../SERVICES/STD_TYPES.h"
#include "../SERVICES/BIT_MATH.h"
#include "../HAL/SWITCH/SWITCH_interface.h"
#include "UART_test.h"
#include "ISR_Actions.h"

#define MOTOR_PORT GPIO_PORTC
#define MOTOR_PIN1 GPIO_PIN0
#define MOTOR_PIN2 GPIO_PIN2

#define LED_PORT   GPIO_PORTC
#define LED_PIN    GPIO_PIN1

/* Callback */

void Bluetooth_UART_Callback(u8 Copy_u8Data)
{
    if (Copy_u8Data == 'f') // forward
    {
        GPIO_SetPinValue(MOTOR_PORT, MOTOR_PIN1, GPIO_HIGH);
        GPIO_SetPinValue(MOTOR_PORT, MOTOR_PIN2, GPIO_LOW);
        GPIO_SetPinValue(LED_PORT, LED_PIN, GPIO_HIGH);
    }
    else if (Copy_u8Data == 's') // stop
    {
        GPIO_SetPinValue(MOTOR_PORT, MOTOR_PIN1, GPIO_LOW);
        GPIO_SetPinValue(MOTOR_PORT, MOTOR_PIN2, GPIO_LOW);
        GPIO_SetPinValue(LED_PORT, LED_PIN, GPIO_LOW);
    }
}

// ES_Drivers/APP/UART_test.c  (relevant while loop)
void UART_Test(void)
{
    GPIO_SetPinDirection(MOTOR_PORT, MOTOR_PIN1, GPIO_OUTPUT);
    GPIO_SetPinDirection(MOTOR_PORT, MOTOR_PIN2, GPIO_OUTPUT);
    GPIO_SetPinDirection(LED_PORT, LED_PIN, GPIO_OUTPUT);
    UART_RX_Init();
    UART_TX_Init();

    SET_BIT(PIE1, RCIE);   // UART RX interrupt enable
    SET_BIT(INTCON, PEIE); // Peripheral interrupt
    SET_BIT(INTCON, GIE);  // Global interrupt

    while(1)
    {
        if (g_flag_uart_rx)
        {
            g_flag_uart_rx = 0;
            Bluetooth_UART_Callback(g_uart_rx_byte);
        }
    }
}
