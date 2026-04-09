#include "uart_test.h"
#include "../MCAL/USART/USART_Interface.h"

void APP_UART_Test(void)
{
    /* Variables declared at top for C89 compatibility */
    u8 ch;

    UART_TX_Init();
    UART_RX_Init();

    /* Echo loop: receive a byte and send it back */
    while (1)
    {
        ch = UART_Read();
        UART_Write(ch);
    }
}