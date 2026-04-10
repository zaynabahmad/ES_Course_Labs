#include "APP_Tests.h"
#include "../HAL/LED/LED_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/USART/USART_Interface.h"

#define MOTOR_PORT GPIO_PORTC
#define MOTOR_PIN1 GPIO_PIN0
#define MOTOR_PIN2 GPIO_PIN2

static void Bluetooth_UART_Callback(u8 UART_data)
{
    if (UART_data == 'f')  // forward
    {
        GPIO_SetPinValue(MOTOR_PORT, MOTOR_PIN1, GPIO_HIGH);
        GPIO_SetPinValue(MOTOR_PORT, MOTOR_PIN2, GPIO_LOW);
    }
    else if (UART_data == 's') // stop
    {
        GPIO_SetPinValue(MOTOR_PORT, MOTOR_PIN1, GPIO_LOW);
        GPIO_SetPinValue(MOTOR_PORT, MOTOR_PIN2, GPIO_LOW);
    }
}

void APP_Test_UART(void)
{
    GPIO_SetPinDirection(MOTOR_PORT, MOTOR_PIN1, GPIO_OUTPUT);
    GPIO_SetPinDirection(MOTOR_PORT, MOTOR_PIN2, GPIO_OUTPUT);

    UART_RX_Init();
    UART_TX_Init();
    UART_SetCallback(Bluetooth_UART_Callback);

    // Test logic runs via interrupts, so this function just sets it up.
}
