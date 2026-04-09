#include "../SERVICES/STD_TYPES.h"
#include "../MCAL/USART/USART_Interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../HAL/LED/LED_interface.h"

#define LED_PORT  GPIO_PORTA
#define LED_PIN   GPIO_PIN0

void UART_Callback_Handler(u8 data)
{
    UART_Write(data);

    if(data == '1') { // LED ON
        LED_On(LED_PORT, LED_PIN);
        UART_Write('\n');
    }
    else if(data == '0') { // LED OFF
        LED_Off(LED_PORT, LED_PIN);
        UART_Write('\n');
    }
    else if(data == 't' || data == 'T') { // Toggle
        LED_Toggle(LED_PORT, LED_PIN);
        UART_Write('\n');
    }
}

void UART_Test(void)
{
    GPIO_Init();
    LED_Init(LED_PORT, LED_PIN);
    LED_Off(LED_PORT, LED_PIN);
    UART_RX_Init();
    UART_TX_Init();
    UART_SetCallback(UART_Callback_Handler);
    UART_Write('R'); UART_Write('e'); UART_Write('a'); UART_Write('d'); UART_Write('y'); UART_Write('\n');
}
