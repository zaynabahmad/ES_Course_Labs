
#include "I2C_interface.h"

/* ------------------------------------------------------------ */
void I2C_Init(void)
{
    TRISC3_bit = 1;     /* RC3/SCL = input (open-drain) */
    TRISC4_bit = 1;     /* RC4/SDA = input (open-drain) */

    SSPCON  = 0x28;     /* Master mode, Fosc/4          */
    SSPSTAT = 0x00;     /* Standard speed, clear flags  */
}

/* ------------------------------------------------------------ */
void I2C_Start(void)
{
    SEN_bit = 1;
    while (SEN_bit);    /* Wait for START condition done */
}

/* ------------------------------------------------------------ */
void I2C_Stop(void)
{
    PEN_bit = 1;
    while (PEN_bit);    /* Wait for STOP condition done  */
}

/* ------------------------------------------------------------ */
void I2C_Write(char d)
{
    SSPBUF = d;
    while (!SSPIF_bit);     /* Wait for transmission done */
    SSPIF_bit = 0;          /* Clear flag                 */
}

/* ------------------------------------------------------------ */
/* ack = 1 -> send ACK (more bytes follow)
 * ack = 0 -> send NACK (last byte)           */
char I2C_Read(char ack)
{
    RCEN_bit = 1;
    while (!SSPIF_bit);     /* Wait for byte received     */
    SSPIF_bit = 0;

    ACKDT_bit = (ack ? 0 : 1);   /* 0 = ACK, 1 = NACK   */
    ACKEN_bit = 1;
    while (ACKEN_bit);      /* Wait for ACK/NACK sent     */

    return SSPBUF;
}