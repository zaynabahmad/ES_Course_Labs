#include "USART_Interface.h"

/* =================================
   RX queue (ISR only enqueues;
   UART_ServiceRx runs callbacks in main)

/* =================================
   Global Pointer To Callback
================================= */

void (*UART_Callback)(u8) = 0;

/* =================================
   RX Initialization
================================= */

void UART_RX_Init(void)
{
    UART_RxWriteIdx = 0;
    UART_RxReadIdx  = 0;

    SET_BIT(TXSTA , BRGH);
    SPBRG = 25;
    CLR_BIT(TXSTA , SYNC);
    SET_BIT(RCSTA , SPEN);
    SET_BIT(RCSTA , CREN);
    SET_BIT(PIE1 , RCIE);
    SET_BIT(INTCON , PEIE);
    SET_BIT(INTCON , GIE);
}

/* =================================
   TX Initialization
================================= */

void UART_TX_Init(void)
{
    SET_BIT(TXSTA , BRGH);
    SPBRG = 25;
    CLR_BIT(TXSTA , SYNC);
    SET_BIT(RCSTA , SPEN);
    SET_BIT(TXSTA , TXEN);
}

/* =================================
   Send Byte
================================= */

void UART_Write(u8 Data)
{
    while(!GET_BIT(TXSTA , TRMT));
    TXREG = Data;
}

/* =================================
   Receive Byte (Polling)
================================= */

u8 UART_Read(void)
{
    while(!GET_BIT(PIR1 , RCIF));
    return RCREG;
}

/* =================================
   TX Buffer Status
================================= */

u8 UART_TX_Empty(void)
{
    return GET_BIT(TXSTA , TRMT);
}

/* =================================
   Callback Setter
================================= */

void UART_SetCallback(void (*Callback)(u8))
{
    if(Callback != 0)
    {
        UART_Callback = Callback;
    }
}

/* =================================
   Drain RX queue in main context
   (calls registered callback)
