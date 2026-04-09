#include "uart_interface.h"
#include "uart_private.h"
#include "uart_config.h"
#include "../../SERVICES/bit_ops.h"

void UART_Configure(void)
{
    BIT_CLEAR(TRISC_REG, 6);
    BIT_SET(TRISC_REG, 7);

    SPBRG_REG = 51;   /* 9600 baud with BRGH=1, Fosc=8MHz */

    BIT_SET(TXSTA_REG, BRGH);
    BIT_CLEAR(TXSTA_REG, SYNC);
    BIT_SET(TXSTA_REG, TXEN);

    BIT_SET(RCSTA_REG, SPEN);
    BIT_SET(RCSTA_REG, CREN);
}

void UART_TransmitByte(u8 byte)
{
    while(!BIT_READ(TXSTA_REG, TRMT));
    TXREG_REG = byte;
}

u8 UART_ReceiveByte(void)
{
    while(!BIT_READ(PIR1_REG, RCIF));
    return RCREG_REG;
}

void UART_TransmitString(unsigned char* str)
{
    while(*str)
    {
        UART_TransmitByte(*str++);
    }
}