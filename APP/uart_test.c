#include "app_tests.h"

#include "../MCAL/USART/USART_Interface.h"

void APP_Test_UART(void)
{
    UART_Init();
    UART_WriteString((const unsigned char*)"UART Ready\r\n");
}
