#include "USART_Interface.h"

void (*UART_Callback)(u8) = 0;

void UART_TX_Init(void)
{
    SPBRG = UART_SPBRG_VALUE;

    CLR_BIT(TXSTA, SYNC);
    SET_BIT(TXSTA, BRGH);
    SET_BIT(TXSTA, TXEN);

    SET_BIT(RCSTA, SPEN);
}

void UART_RX_Init(void)
{
    SPBRG = UART_SPBRG_VALUE;

    CLR_BIT(TXSTA, SYNC);
    SET_BIT(TXSTA, BRGH);

    SET_BIT(RCSTA, SPEN);
    SET_BIT(RCSTA, CREN);

    SET_BIT(PIE1, RCIE);
    SET_BIT(INTCON, PEIE);
    SET_BIT(INTCON, GIE);
}

void UART_Write(u8 Data)
{
    while(!GET_BIT(TXSTA, TRMT)) { ; }
    TXREG = Data;
}

u8 UART_Read(void)
{
    while(!GET_BIT(PIR1, RCIF)) { ; }
    return RCREG;
}

u8 UART_TX_Empty(void)
{
    return GET_BIT(TXSTA, TRMT);
}

void UART_SetCallback(void (*Callback)(u8))
{
    if(Callback != 0)
    {
        UART_Callback = Callback;
    }
}

void UART_ISR(void)
{
    u8 received = RCREG;
    if(UART_Callback != 0)
    {
        UART_Callback(received);
    }
}
