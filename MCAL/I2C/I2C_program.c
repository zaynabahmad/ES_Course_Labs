#include "I2C_interface.h"
#include "I2C_private.h"

void I2C_Init(void)
{
    TRISC3_bit = 1;   /* scl */
    TRISC4_bit = 1;   /* sda */

    SSPCON  = 0x28;   /* i2c master mode */
    SSPSTAT = 0x00;
}

void I2C_Start(void)
{
    SEN_bit = 1;
    while (SEN_bit);
}

void I2C_Stop(void)
{
    PEN_bit = 1;
    while (PEN_bit);
}

void I2C_Write(unsigned char data)
{
    SSPBUF = data;
    while (!SSPIF_bit);
    SSPIF_bit = 0;
}

unsigned char I2C_Read(unsigned char send_ack)
{
    RCEN_bit = 1;
    while (!SSPIF_bit);
    SSPIF_bit = 0;

    ACKDT_bit = (send_ack == I2C_ACK) ? 0 : 1;
    ACKEN_bit = 1;
    while (ACKEN_bit);

    return SSPBUF;
}