#include "../SERVICES/STD_TYPES.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/UART/UART_interface.h"

void APP_UART_Test(void) 
{
    /* 1. Setup GPIO Directions for UART Pins */
    /* RC6 is TX (Output), RC7 is RX (Input) */
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN6, GPIO_OUTPUT);
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN7, GPIO_INPUT);

    /* 2. Initialize UART Driver */
    UART_Init();

    /* 3. Send a Welcome Message to the Virtual Terminal */
    UART_WriteText("UART Driver Test Initialized...\r\n");
    UART_WriteText("Type a character to echo it back: ");

    while(1) 
    {
        /* * Note: For a full 'test', we would normally have a UART_ReadChar function.
         * If you just want to test transmission for your ADC lab:
         */
        UART_WriteText("Testing Transmission...\r\n");
        
        /* Small delay */
        for(volatile uint32 i = 0; i < 50000; i++);
    }
}
#ifndef Delay_ms
  #define Delay_ms(x)  // Dummy macro for GCC syntax check
#endif
#ifndef Delay_us
  #define Delay_us(x)  // Dummy macro for GCC syntax check
#endif