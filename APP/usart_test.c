#include "../SERVICES/STD_TYPES.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/USART/USART_interface.h"
#include "usart_test.h"

// Hardware Pin Definitions 
#define MOTOR_PORT  GPIO_PORTC
#define MOTOR_PIN1  GPIO_PIN0
#define MOTOR_PIN2  GPIO_PIN2
#define LED_PORT    GPIO_PORTC
#define LED_PIN     GPIO_PIN1

// THE CALLBACK FUNCTION (Application Logic)

static void APP_Bluetooth_Callback(u8 UART_data)
{
    // Optional: Echo the character back so you can see what you typed in Proteus!
    UART_Write(UART_data);
    UART_Write('\r'); // Carriage Return
    UART_Write('\n'); // Line Feed

    if (UART_data == 'f')  // 'f' for forward
    {
        GPIO_SetPinValue(MOTOR_PORT, MOTOR_PIN1, GPIO_HIGH);
        GPIO_SetPinValue(MOTOR_PORT, MOTOR_PIN2, GPIO_LOW);
        GPIO_SetPinValue(LED_PORT, LED_PIN, GPIO_HIGH); // Turn ON indicator LED
    }
    else if (UART_data == 's') // 's' for stop
    {
        GPIO_SetPinValue(MOTOR_PORT, MOTOR_PIN1, GPIO_LOW);
        GPIO_SetPinValue(MOTOR_PORT, MOTOR_PIN2, GPIO_LOW);
        GPIO_SetPinValue(LED_PORT, LED_PIN, GPIO_LOW);  // Turn OFF indicator LED
    }
}

void APP_TestUSART(void)
{
    // Initialize GPIOs
    GPIO_Init();
    GPIO_SetPinDirection(MOTOR_PORT, MOTOR_PIN1, GPIO_OUTPUT);
    GPIO_SetPinDirection(MOTOR_PORT, MOTOR_PIN2, GPIO_OUTPUT);
    GPIO_SetPinDirection(LED_PORT, LED_PIN, GPIO_OUTPUT);

    // Initialize UART (We need both RX to read the keyboard, and TX to echo)
    UART_RX_Init();
    UART_TX_Init();

    // Hand the application function over to the UART driver
    UART_SetCallback(APP_Bluetooth_Callback);

    // Send a welcome message to the Virtual Terminal
    UART_Write('R'); UART_Write('e'); UART_Write('a'); UART_Write('d'); UART_Write('y'); 
    UART_Write('!'); UART_Write('\r'); UART_Write('\n');

    // Infinite Loop
    while(1)
    {
        // CPU is free! 
        // Whenever a letter is typed in the Virtual Terminal, the hardware 
        // interrupts the CPU and runs the callback function automatically.
    }
}