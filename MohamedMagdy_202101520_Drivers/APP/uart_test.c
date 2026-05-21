#include "../MCAL/USART/USART_Interface.h"
#include "uart_test.h"

static void UART_Echo_Callback(u8 received_byte)
{
    UART_Write(received_byte);
}

static void UART_SendString(const char *str)
{
    while(*str != '\0')
    {
        UART_Write((u8)*str);
        str++;
    }
}

void UART_Test(void)
{
    UART_TX_Init();

    UART_SendString("UART Test Start\r\n");

    while(!UART_TX_Empty()) { ; }

    UART_RX_Init();

    UART_SetCallback(UART_Echo_Callback);

    UART_SendString("Echo mode active. Type to echo.\r\n");
}
