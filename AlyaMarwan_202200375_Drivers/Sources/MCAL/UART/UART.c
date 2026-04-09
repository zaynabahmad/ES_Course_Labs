#include "uart.h"
#include "bit_math.h"

int UART_TxData = 0;

void UART_Init(void)
{
    SPBRG = 51;
    TXSTA = 0x24;
    RCSTA = 0x90;
    CLR_BIT(TRISC, 6);
    SET_BIT(TRISC, 7);
}

void UART_SendChar(void)
{
    while(GET_BIT(PIR1, 4) == 0);
    TXREG = UART_TxData;
}

int UART_ReceiveChar(void)
{
    while(GET_BIT(PIR1, 5) == 0);
    return RCREG;
}

int UART_DataAvailable(void)
{
    return GET_BIT(PIR1, 5);
}