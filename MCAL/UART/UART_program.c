#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"

#include "../../SERVICES/BIT_MATH.h"

void UART_Init(void)
{
    CLR_BIT(TRISC, 6);
    SET_BIT(TRISC, 7);

    SPBRG = 51;

    SET_BIT(TXSTA, BRGH);
    CLR_BIT(TXSTA, SYNC);
    SET_BIT(TXSTA, TXEN);

    SET_BIT(RCSTA, SPEN);
    SET_BIT(RCSTA, CREN);
}

void UART_SendChar(u8 byte)
{
    while (!GET_BIT(TXSTA, TRMT));
    TXREG = byte;
}

u8 UART_ReceiveChar(void)
{
    while (!GET_BIT(PIR1, RCIF));
    return RCREG;
}

void UART_SendString(u8* str)
{
    while (*str != '\0')
    {
        UART_SendChar(*str);
        str++;
    }
}