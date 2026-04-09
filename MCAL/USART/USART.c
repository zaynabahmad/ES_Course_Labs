#include "USART_Interface.h"

void (*UART_Callback)(u8) = 0;

void UART_RX_Init(void)
{
    SET_BIT(TXSTA, BRGH);       /* High Speed Mode */
    SPBRG = 25;                 /* 9600 baud @ 4MHz */
    CLR_BIT(TXSTA, SYNC);       /* Asynchronous Mode */
    SET_BIT(RCSTA, SPEN);       /* Enable Serial Port */
    SET_BIT(RCSTA, CREN);       /* Continuous Receive */
    SET_BIT(PIE1, RCIE);        /* Enable UART RX Interrupt */
    SET_BIT(INTCON, PEIE);      /* Peripheral Interrupt Enable */
    SET_BIT(INTCON, GIE);       /* Global Interrupt Enable */
}

void UART_TX_Init(void)
{
    SET_BIT(TXSTA, BRGH);
    SPBRG = 25;
    CLR_BIT(TXSTA, SYNC);
    SET_BIT(RCSTA, SPEN);
    SET_BIT(TXSTA, TXEN);
}

void UART_Write(u8 Data)
{
    while(!GET_BIT(TXSTA, TRMT));
    TXREG = Data;
}

void UART_WriteString(const u8 *Str)
{
    while(*Str)
    {
        UART_Write(*Str);
        Str++;
    }
}

u8 UART_Read(void)
{
    while(!GET_BIT(PIR1, RCIF));
    return RCREG;
}

u8 UART_TX_Empty(void)
{
    return GET_BIT(TXSTA, TRMT);
}

void UART_SetCallback(void (*Callback)(u8))
{
    if(Callback != 0)
        UART_Callback = Callback;
}

void UART_ISR(void)
{
    u8 data = RCREG;
    if(UART_Callback != 0)
        UART_Callback(data);
}
