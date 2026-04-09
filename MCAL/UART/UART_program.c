#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"
#include "../../SERVICES/BIT_MATH.h"
#include "../../SERVICES/STD_TYPES.h"

/* ════════════════════════════════════════
   INIT
   ════════════════════════════════════════ */
void UART_Init(void)
{
    /* RC6 = TX → output, RC7 = RX → input */
    CLR_BIT(TRISC, TRISC6);
    SET_BIT(TRISC, TRISC7);

    /* Baud rate: SPBRG = (Fosc / (16 * Baud)) - 1  when BRGH=1 */
    SPBRG = UART_SPBRG_9600;

    /* TXSTA: async mode, high baud rate, enable transmitter */
    CLR_BIT(TXSTA, TXSTA_SYNC);    /* Async mode         */
    SET_BIT(TXSTA, TXSTA_BRGH);    /* High baud rate     */
    SET_BIT(TXSTA, TXSTA_TXEN);    /* Enable transmitter */

    /* RCSTA: enable serial port, enable continuous receive */
    SET_BIT(RCSTA, RCSTA_SPEN);    /* Serial port enable */
    SET_BIT(RCSTA, RCSTA_CREN);    /* Continuous receive */

    
}

/* ════════════════════════════════════════
   SEND FUNCTIONS
   ════════════════════════════════════════ */

void UART_SendByte(u8 byte)
{
    /* Wait until transmit register is empty */
    while (GET_BIT(PIR1, PIR1_TXIF) == 0);
    TXREG = byte;
}

void UART_SendString(const u8 *str)
{
    while (*str != '\0')
    {
        UART_SendByte(*str);
        str++;
    }
}

void UART_SendNewLine(void)
{
    UART_SendByte(13);   /* CR */
    UART_SendByte(10);   /* LF */
}

void UART_SendNumber(u32 num)
{
    u8 buf[10];
    u8 i = 0;

    if (num == 0)
    {
        UART_SendByte('0');
        return;
    }

    /* Extract digits in reverse */
    while (num > 0u)
    {
        buf[i] = (u8)((num % 10u) + '0');
        num   /= 10u;
        i++;
    }

    /* Send in correct order */
    while (i > 0u)
    {
        i--;
        UART_SendByte(buf[i]);
    }
}

/* ════════════════════════════════════════
   RECEIVE FUNCTIONS
   ════════════════════════════════════════ */

/* Returns 1 if a byte is waiting in RCREG, 0 otherwise */
u8 UART_IsDataReady(void)
{
    return GET_BIT(PIR1, PIR1_RCIF);
}

/* Blocking: waits until a byte arrives then returns it.
   Also clears overrun error automatically if it occurs.  */
u8 UART_ReceiveByte(void)
{
    /* If overrun error occurred, clear it by toggling CREN */
    if (GET_BIT(RCSTA, RCSTA_OERR) == 1)
    {
        CLR_BIT(RCSTA, RCSTA_CREN);
        SET_BIT(RCSTA, RCSTA_CREN);
    }

    /* Wait until receive buffer is full */
    while (GET_BIT(PIR1, PIR1_RCIF) == 0);

    return RCREG;   /* Reading RCREG clears RCIF automatically */
}

/* Non-blocking: if a byte is ready, store it in *byte and return 1.
   If nothing received yet, return 0 without blocking.             */
u8 UART_ReceiveByte_NoBlock(u8 *byte)
{
    if (GET_BIT(PIR1, PIR1_RCIF) == 1)
    {
        *byte = RCREG;
        return 1u;
    }
    return 0u;
}

/* Reads characters into buf until '\r' is received or maxLen-1
   chars are stored. Always null-terminates the buffer.           */
void UART_ReceiveString(u8 *buf, u8 maxLen)
{
    u8 i   = 0;
    u8 ch  = 0;

    while (i < (maxLen - 1u))
    {
        ch = UART_ReceiveByte();

        if (ch == '\r')   /* Enter key = end of string */
        {
            break;
        }

        buf[i] = ch;
        i++;
    }

    buf[i] = '\0';   /* Null-terminate */
}

