#include "UART_INTERFACE.h"
#include "UART_PRIVATE.h"
#include "UART_CONFIG.h"
#include "../SERVICES/BIT_MATH.h"

void UART_Init(void)
{
    /* RC6=TX output, RC7=RX input */
    CLR_BIT(TRISC, 6);
    SET_BIT(TRISC, 7);

    /* Set baud rate */
    SPBRG = UART_SPBRG_VALUE;

    /* TXSTA: asynchronous mode, configure baud rate speed */
    CLR_BIT(TXSTA, SYNC);
#if UART_HIGH_SPEED == 1
    SET_BIT(TXSTA, BRGH);
#else
    CLR_BIT(TXSTA, BRGH);
#endif
    SET_BIT(TXSTA, TXEN); /* Enable transmitter */

    /* RCSTA: enable serial port and continuous receive */
    SET_BIT(RCSTA, SPEN);
    SET_BIT(RCSTA, CREN);
}

void UART_SendByte(u8 data)
{
    /* Wait until TXREG is empty (TXIF=1) */
    while(GET_BIT(PIR1, TXIF) == 0);
    TXREG = data;
}

u8 UART_ReceiveByte(void)
{
    /* Wait until a byte is received (RCIF=1) */
    while(GET_BIT(PIR1, RCIF) == 0);
    return RCREG;
}

void UART_SendString(u8 *str)
{
    while(*str != '\0')
    {
        UART_SendByte(*str);
        str++;
    }
}

u8 UART_IsDataAvailable(void)
{
    return GET_BIT(PIR1, RCIF);
}
