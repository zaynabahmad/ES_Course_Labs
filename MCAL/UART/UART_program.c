#include "D:\Uni\Y4 S2\Embedded Systems\Final\SERVICES\STD_TYPES.h"
#include "D:\Uni\Y4 S2\Embedded Systems\Final\SERVICES\BIT_MATH.h"
#include "D:\Uni\Y4 S2\Embedded Systems\Final\MCAL\UART\UART_private.h"
#include "D:\Uni\Y4 S2\Embedded Systems\Final\MCAL\UART\UART_interface.h"

/* ---------------------------------------------------------- */
void UART_voidClearErrors(void)
{
    CLR_BIT(RCSTA, RCSTA_CREN);
    SET_BIT(RCSTA, RCSTA_CREN);
}

/* ---------------------------------------------------------- */
void UART_voidInit(void)
{
    SET_BIT(TRISC, UART_RX_PIN);    /* RC7 input  */
    CLR_BIT(TRISC, UART_TX_PIN);    /* RC6 output */

    SPBRG = UART_SPBRG_VALUE;

    CLR_BIT(TXSTA, TXSTA_SYNC);    /* async mode     */
    SET_BIT(TXSTA, TXSTA_BRGH);    /* high speed     */
    CLR_BIT(TXSTA, TXSTA_TX9);     /* 8-bit frame    */
    SET_BIT(TXSTA, TXSTA_TXEN);    /* enable TX      */

    SET_BIT(RCSTA, RCSTA_SPEN);    /* enable serial port */
    CLR_BIT(RCSTA, RCSTA_RX9);     /* 8-bit frame        */
    SET_BIT(RCSTA, RCSTA_CREN);    /* enable RX          */
}

/* ---------------------------------------------------------- */
void UART_voidSendChar(unsigned char data)
{

    while (GET_BIT(PIR1, PIR1_TXIF) == 0u)
    {
        /* spin */
    }
    TXREG = data;
}

/* ---------------------------------------------------------- */
void UART_voidSendString(const unsigned char *str)
{

    while (*str != '\0')
    {
        UART_voidSendChar(*str);
        str++;
    }
}

/* ---------------------------------------------------------- */
void UART_voidSendNumber(unsigned int number)
{
    unsigned char digits[5];
    unsigned char count = 0u;
    unsigned char i;


    if (number == 0u)
    {
        UART_voidSendChar('0');
        return;
    }


    while (number > 0u)
    {
        digits[count] = (unsigned char)((number % 10u) + '0');
        number /= 10u;
        count++;
    }


    for (i = count; i > 0u; i--)
    {
        UART_voidSendChar(digits[i - 1u]);
    }
}

/* ---------------------------------------------------------- */
unsigned char UART_u8ReceiveChar(unsigned char *received)
{

    if (GET_BIT(RCSTA, RCSTA_OERR))
    {
        UART_voidClearErrors();
        return UART_ERR_OVERRUN;
    }


    while (GET_BIT(PIR1, PIR1_RCIF) == 0u)
    {
        /* spin */
    }


    if (GET_BIT(RCSTA, RCSTA_FERR))
    {
        *received = RCREG;
        return UART_ERR_FRAMING;
    }

    *received = RCREG;
    return UART_OK;
}

/* ---------------------------------------------------------- */
unsigned char UART_u8ReceiveCharTimeout(unsigned char *received)
{
    unsigned int timeout = UART_RX_TIMEOUT;

    /* Check for overrun first */
    if (GET_BIT(RCSTA, RCSTA_OERR))
    {
        UART_voidClearErrors();
        return UART_ERR_OVERRUN;
    }


    while (GET_BIT(PIR1, PIR1_RCIF) == 0u)
    {
        timeout--;
        if (timeout == 0u)
        {
            return UART_ERR_TIMEOUT;
        }
    }

    *received = RCREG;
    return UART_OK;
}