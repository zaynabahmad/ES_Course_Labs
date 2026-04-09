#include "app_tests.h"

#include "../MCAL/USART/USART_Interface.h"

void APP_Test_USART(void)
{
    USART_Init();
    USART_WriteString((const unsigned char*)"USART Ready\r\n");
}
