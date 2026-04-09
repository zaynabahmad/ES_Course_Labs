#include "i2c_interface.h"
#include "i2c_private.h"
#include "i2c_config.h"
#include "../../SERVICES/bit_ops.h"

void I2C_Configure(void)
{
    BIT_SET(TRISC_REG, 3);   /* SCL input */
    BIT_SET(TRISC_REG, 4);   /* SDA input */

    SSPCON_REG = 0x28;       /* I2C Master mode */
    SSPADD_REG = 19;         /* 100kHz @ 8MHz */
    SSPSTAT_REG = 0x00;

    BIT_SET(SSPCON_REG, SSPEN);
}

void I2C_GenerateStart(void)
{
    BIT_SET(SSPCON2_REG, SEN);
    while(BIT_READ(SSPCON2_REG, SEN));
}

void I2C_GenerateStop(void)
{
    BIT_SET(SSPCON2_REG, PEN);
    while(BIT_READ(SSPCON2_REG, PEN));
}

void I2C_SendByte(unsigned char byte)
{
    SSPBUF = byte;
    while(!BIT_READ(PIR1, SSPIF));
    BIT_CLEAR(PIR1, SSPIF);
}

unsigned char I2C_ReceiveByte(unsigned char ack)
{
    unsigned char received;
    BIT_SET(SSPCON2, RCEN);
    while(!BIT_READ(PIR1, SSPIF));
    received = SSPBUF;
    BIT_CLEAR(PIR1, SSPIF);

    if(ack)
        BIT_CLEAR(SSPCON2, ACKDT);
    else
        BIT_SET(SSPCON2, ACKDT);
    BIT_SET(SSPCON2, ACKEN);
    while(BIT_READ(SSPCON2, ACKEN));
    return received;
}