#include "app_tests.h"

#include "../MCAL/UART/UART_Interface.h"

void APP_Test_UART(void)
{
    UART_Init();
    UART_WriteString((const unsigned char*)"UART Ready\r\n");
}

void APP_Test_USART(void)
{
    UART_Init();
    UART_WriteString((const unsigned char*)"USART Ready\r\n");
}
