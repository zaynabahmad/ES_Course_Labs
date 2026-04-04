#include "USART_Interface.h"


/* =================================
   Global Pointer To Callback
================================= */

void (*UART_Callback)(u8) = 0;

/* =================================
   RX Initialization
================================= */

void UART_RX_Init(void)
{

    SET_BIT(TXSTA , BRGH);              /* High Speed Mode */

    SPBRG = UART_SPBRG_VALUE;          /* Baud rate from config */

    CLR_BIT(TXSTA , SYNC);      // Asynchronous Mode

    SET_BIT(RCSTA , SPEN);      // Enable Serial Port

    SET_BIT(RCSTA , CREN);      // Continuous Receive

    SET_BIT(PIE1 , RCIE);       // Enable UART RX Interrupt

    SET_BIT(INTCON , PEIE);     // Peripheral Interrupt Enable
    SET_BIT(INTCON , GIE);      // Global Interrupt Enable
}

/* =================================
   TX Initialization
================================= */

void UART_TX_Init(void)
{

    SET_BIT(TXSTA , BRGH);              /* High Speed */

    SPBRG = UART_SPBRG_VALUE;          /* Baud rate from config */

    CLR_BIT(TXSTA , SYNC);      // Asynchronous Mode

    SET_BIT(RCSTA , SPEN);      // Enable Serial Port

    SET_BIT(TXSTA , TXEN);      // Enable Transmission
}

/* =================================
   Send Byte
================================= */

void UART_Write(u8 Data)
{

    while(!GET_BIT(TXSTA , TRMT));   // Wait until TX empty

    TXREG = Data;
}

/* =================================
   Receive Byte (Polling)
================================= */

u8 UART_Read(void)
{

    while(!GET_BIT(PIR1 , RCIF));    // Wait for data

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

void UART_ISR(void)
{

    u8 UART_data = RCREG;   //
    if(UART_Callback != 0)
    {
        UART_Callback(UART_data);   //
    }

}


/* =================================
   ISR Handler
================================= */

/*
void interrupt()
{

   if(GET_BIT(PIR1 , RCIF))
    {

        if(UART_Callback != 0)
        {
            UART_Callback();   // Call user function
        }

    }

}
  */