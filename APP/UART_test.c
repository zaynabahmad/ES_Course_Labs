
#include "../MCAL/USART/USART_Interface.h"
#include "../MCAL/USART/USART_Config.h"


static volatile u8 ReceivedChar = 0;
static volatile u8 NewDataFlag  = 0;



void APP_Test_UART(void)
{

    #if UART_ECHO_MODE == 1
    if (NewDataFlag == 1)
    {

        UART_Write(UART_DEBUG_CHAR);

        UART_Write(ReceivedChar);
        UART_Write('\r');
        UART_Write('\n');

        NewDataFlag = 0;
    }
    #endif
}