#include "../MCAL/USART/USART_Interface.h"
#include "uart_test.h"

static void uart_rx_handler(u8 data)
{
    /* Echo received byte back */
    UART_Write(data);
}

void uart_test_run(void)
{
    UART_TX_Init();
    UART_RX_Init();

    UART_SetCallback(uart_rx_handler);

    /* Send a greeting string */
    UART_Write('U');
    UART_Write('A');
    UART_Write('R');
    UART_Write('T');
    UART_Write(':');
    UART_Write('O');
    UART_Write('K');
    UART_Write('\r');
    UART_Write('\n');
}
