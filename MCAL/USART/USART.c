#include "USART_Interface.h"
#include "USART_Private.h"
#include "USART_Config.h"

#include "../../SERVICES/BIT_MATH.h"


/* Global Pointer To Callback */

static volatile u8 UART_LastRxData = 0U;
static volatile u8 UART_RxPending = 0U;

/* RX Initialization */

void UART_RX_Init(void)
{
    if (UART_HIGH_SPEED == 1)
    {
        SET_BIT(TXSTA , BRGH);
    }
    else
    {
        CLR_BIT(TXSTA , BRGH);
    }

    SPBRG = 25U;

    CLR_BIT(TXSTA , SYNC);      // Asynchronous Mode

    SET_BIT(RCSTA , SPEN);      // Enable Serial Port

    SET_BIT(RCSTA , CREN);      // Continuous Receive

    SET_BIT(PIE1 , RCIE);       // Enable UART RX Interrupt

    SET_BIT(INTCON , PEIE);     // Peripheral Interrupt Enable
    SET_BIT(INTCON , GIE);      // Global Interrupt Enable
}

/* TX Initialization */

void UART_TX_Init(void)
{
    if (UART_HIGH_SPEED == 1)
    {
        SET_BIT(TXSTA , BRGH);
    }
    else
    {
        CLR_BIT(TXSTA , BRGH);
    }

    SPBRG = 25U;

    CLR_BIT(TXSTA , SYNC);      // Asynchronous Mode

    SET_BIT(RCSTA , SPEN);      // Enable Serial Port

    SET_BIT(TXSTA , TXEN);      // Enable Transmission
}

void UART_Init(void)
{
    UART_TX_Init();
    UART_RX_Init();
}

/* Send Byte */

void UART_Write(u8 Data)
{

    while(!GET_BIT(TXSTA , TRMT));   // Wait until TX empty

    TXREG = Data;
}

void UART_WriteString(const u8* String)
{
    if (String == NULL_PTR)
    {
        return;
    }

    while (*String != '\0')
    {
        UART_Write(*String);
        String++;
    }
}

/* Receive Byte (Polling) */

u8 UART_Read(void)
{

    while(!GET_BIT(PIR1 , RCIF));    // Wait for data

    return RCREG;
}

/* TX Buffer Status */

u8 UART_TX_Empty(void)
{

    return GET_BIT(TXSTA , TRMT);
}

/* Callback Setter */

void UART_SetCallback(void (*Callback)(u8))
{
    (void)Callback;

}

void UART_ISR(void)
{
    UART_LastRxData = RCREG;
    UART_RxPending = 1U;

}

u8 UART_HasPendingByte(void)
{
    return UART_RxPending;
}

u8 UART_GetPendingByte(void)
{
    UART_RxPending = 0U;
    return UART_LastRxData;
}


