#include "UART_Interface.h"
#include "UART_Private.h"
#include "UART_Config.h"

#include "../../SERVICES/BIT_MATH.h"

void UART_Init(void)
{
    if (UART_HIGH_SPEED == 1U)
    {
        SET_BIT(TXSTA, BRGH);
    }
    else
    {
        CLR_BIT(TXSTA, BRGH);
    }

    SPBRG = 25U;
    CLR_BIT(TXSTA, SYNC);
    SET_BIT(RCSTA, SPEN);
    SET_BIT(RCSTA, CREN);
}

void UART_Write(u8 Data)
{
    while (!GET_BIT(TXSTA, TRMT))
    {
    }

    TXREG = Data;
}

u8 UART_Read(void)
{
    while (!GET_BIT(PIR1, RCIF))
    {
    }

    return RCREG;
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

u8 UART_TX_Empty(void)
{
    return GET_BIT(TXSTA, TRMT);
}
