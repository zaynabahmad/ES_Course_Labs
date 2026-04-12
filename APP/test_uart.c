#include "UART_interface.h"

void test_UART(void)
{
    char received;

    UART_Init();
    UART_SendString("hello uart\r\n");

    received = UART_ReceiveByte();
    UART_SendByte(received);   /* echo back */
}
