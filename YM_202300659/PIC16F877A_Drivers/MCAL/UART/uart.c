/*
 * uart.c
 * MCAL - UART Driver Implementation for PIC16F877A
 */

#include "uart.h"
#include "uart_private.h"

void UART_Init(u8 spbrg_val)
{
    /* Step 1: Set RC6 (TX) as output, RC7 (RX) as input */
    TRISC_REG |=  (1 << 7);   /* RC7 = input  (RX) */
    TRISC_REG &= ~(1 << 6);   /* RC6 = output (TX) */

    /* Step 2: Configure baud rate */
    SPBRG_REG = spbrg_val;

    /* Step 3: TXSTA - Async mode, BRGH=1, enable TX */
    TXSTA_REG = 0x00;
    TXSTA_REG |= (1 << TXSTA_TXEN);   /* Enable transmitter */
    TXSTA_REG |= (1 << TXSTA_BRGH);   /* High baud rate     */
    /* SYNC=0: async mode (already cleared)               */

    /* Step 4: RCSTA - Enable serial port and continuous receive */
    RCSTA_REG = 0x00;
    RCSTA_REG |= (1 << RCSTA_SPEN);   /* Enable serial port */
    RCSTA_REG |= (1 << RCSTA_CREN);   /* Enable receiver    */
}

void UART_SendByte(u8 data)
{
    /* Wait until TX register is empty */
    while(!((PIR1_REG >> PIR1_TXIF) & 0x01));
    TXREG_REG = data;
}

void UART_SendString(const u8 *str)
{
    while(*str != '\0')
    {
        UART_SendByte(*str);
        str++;
    }
}

void UART_SendNumber(u16 num)
{
    u8  buf[6];
    u8  i = 0;
    u8  j;
    u8  temp;

    if(num == 0)
    {
        UART_SendByte('0');
        return;
    }
    while(num > 0)
    {
        buf[i++] = (u8)('0' + (num % 10));
        num /= 10;
    }
    /* Reverse the digits */
    for(j = 0; j < i / 2; j++)
    {
        temp       = buf[j];
        buf[j]     = buf[i - 1 - j];
        buf[i-1-j] = temp;
    }
    for(j = 0; j < i; j++)
    {
        UART_SendByte(buf[j]);
    }
}

u8 UART_ReceiveByte(void)
{
    /* Wait until a byte is received */
    while(!UART_IsDataAvailable());
    return RCREG_REG;
}

void UART_ReceiveString(u8 *buf, u8 max_len)
{
    u8 i   = 0;
    u8 ch  = 0;
    while(i < (max_len - 1))
    {
        ch = UART_ReceiveByte();
        if(ch == '\n' || ch == '\r') break;
        buf[i++] = ch;
    }
    buf[i] = '\0';
}

u8 UART_IsDataAvailable(void)
{
    return (PIR1_REG >> PIR1_RCIF) & 0x01;
}

u8 UART_IsTxReady(void)
{
    return (PIR1_REG >> PIR1_TXIF) & 0x01;
}

UART_Error_t UART_GetError(void)
{
    if((RCSTA_REG >> RCSTA_OERR) & 0x01)
    {
        /* Clear overrun by toggling CREN */
        RCSTA_REG &= ~(1 << RCSTA_CREN);
        RCSTA_REG |=  (1 << RCSTA_CREN);
        return UART_ERROR_OVERRUN;
    }
    if((RCSTA_REG >> RCSTA_FERR) & 0x01)
    {
        /* Read RCREG to clear framing error */
        (void)RCREG_REG;
        return UART_ERROR_FRAMING;
    }
    return UART_OK;
}
