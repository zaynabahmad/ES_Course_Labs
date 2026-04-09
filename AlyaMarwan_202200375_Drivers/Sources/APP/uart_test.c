#include "uart.h"

extern int UART_TxData;

void UART_Test(void)
{
    int received = 0;
    int msg[] = {'H','i','i','i','i','i','\r','\n','\0'};

    int i        = 0;

    UART_Init();

    while(msg[i] != '\0')
    {
        UART_TxData = msg[i];
        UART_SendChar();
        i++;
    }

    while(1)
    {
        if(UART_DataAvailable())
        {
            received = UART_ReceiveChar();
            UART_TxData = received;
            UART_SendChar();
        }
    }
}