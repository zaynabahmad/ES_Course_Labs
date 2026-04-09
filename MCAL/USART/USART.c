#include "USART_Private.h"
#include "USART_Config.h"
#include "USART_Interface.h"
#include "../../SERVICES/BIT_MATH.h"

static void (*UART_Callback)(u8) = 0;

/* =================================
   RX Initialization
================================= */
void UART_RX_Init(void)
{
    SET_BIT(TXSTA, BRGH);       /* High Speed Mode */
    SPBRG = 25;                  /* 9600 Baud @ 4MHz BRGH=1 */
    CLR_BIT(TXSTA, SYNC);       /* Asynchronous Mode */
    SET_BIT(RCSTA, SPEN);       /* Enable Serial Port */
    SET_BIT(RCSTA, CREN);       /* Continuous Receive */
    SET_BIT(PIE1, RCIE);        /* Enable UART RX Interrupt */
    SET_BIT(INTCON, PEIE);      /* Peripheral Interrupt Enable */
    SET_BIT(INTCON, GIE);       /* Global Interrupt Enable */
}

/* =================================
   TX Initialization
================================= */
void UART_TX_Init(void)
{
    SET_BIT(TXSTA, BRGH);       /* High Speed */
    SPBRG = 25;                  /* 9600 Baud @ 4MHz BRGH=1 */
    CLR_BIT(TXSTA, SYNC);       /* Asynchronous Mode */
    SET_BIT(RCSTA, SPEN);       /* Enable Serial Port */
    SET_BIT(TXSTA, TXEN);       /* Enable Transmission */
}

/* =================================
   Send Byte
================================= */
void UART_Write(u8 Data)
{
    while (!GET_BIT(TXSTA, TRMT));  /* Wait until TX shift register empty */
    TXREG = Data;
}

/* =================================
   Receive Byte (Polling)
================================= */
u8 UART_Read(void)
{
    while (!GET_BIT(PIR1, RCIF));   /* Wait for data */
    return RCREG;
}

/* =================================
   TX Buffer Status
================================= */
u8 UART_TX_Empty(void)
{
    return GET_BIT(TXSTA, TRMT);
}

/* =================================
   Callback Setter
================================= */
void UART_SetCallback(void (*Callback)(u8))
{
    if (Callback != 0)
        UART_Callback = Callback;
}

/* =================================
   ISR Handler — called from Interrupt_Manager
================================= */
void UART_ISR(void)
{
    if (GET_BIT(PIR1, RCIF))
    {
        u8 data = RCREG;
        if (UART_Callback != 0)
            UART_Callback(data);
    }
}
