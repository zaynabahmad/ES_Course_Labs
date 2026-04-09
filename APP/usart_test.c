#include "USART_Interface.h"

void usart_test_run(void) {

    UART_TX_Init();
    UART_RX_Init();
    
    UART_Write('U');
    UART_Write('A');
    UART_Write('R');
    UART_Write('T');
    UART_Write(' ');
    UART_Write('O');
    UART_Write('K');
}