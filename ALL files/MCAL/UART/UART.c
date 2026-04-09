#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"

#include "UART_Interface.h"
#include "UART_Private.h"
#include "UART_Config.h"

void UART_Init(void)
{
    /* Baud rate calculation (BRGH = 1) */
    u16 spbrg_value = (UART_FOSC / (16UL * UART_BAUD_RATE)) - 1;

    SPBRG = (u8)spbrg_value;

    /* Enable transmitter */
    SET_BIT(TXSTA, TXEN);

    /* High speed */
    SET_BIT(TXSTA, 2); // BRGH

    /* Enable serial port */
    SET_BIT(RCSTA, SPEN);

    /* Enable receiver */
    SET_BIT(RCSTA, CREN);
}

void UART_Write(u8 Data)
{
    /* Wait until TX buffer is empty */
    while(!GET_BIT(TXSTA, TRMT));

    TXREG = Data;
}

u8 UART_Read(void)
{
    /* Wait until data is received */
    while(!GET_BIT(RCSTA, 5)); // RCIF bit

    return RCREG;
}

void UART_WriteString(const u8* String)
{
    while(*String != '\0')
    {
        UART_Write(*String);
        String++;
    }
}

u8 UART_TX_Empty(void)
{
    return GET_BIT(TXSTA, TRMT);
}