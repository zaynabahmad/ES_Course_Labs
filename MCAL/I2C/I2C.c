#include "I2C_Interface.h"

void I2C_Init(void)
{
    /* SDA (RC4) and SCL (RC3) as inputs (I2C module controls them) */
    SET_BIT(TRISC, 3);
    SET_BIT(TRISC, 4);

    /* Set baud rate */
    SSPADD = (u8)I2C_SSPADD_VALUE;

    /* I2C Master mode (SSPM = 1000) */
    SSPCON = (SSPCON & 0xF0) | 0x08;

    /* Enable MSSP */
    SET_BIT(SSPCON, SSPEN);

    /* Slew rate disabled for 100kHz */
    SET_BIT(SSPSTAT, 7);
}

void I2C_Start(void)
{
    CLR_BIT(PIR1, SSPIF);
    SET_BIT(SSPCON2, SEN);
    while (!GET_BIT(PIR1, SSPIF));
    CLR_BIT(PIR1, SSPIF);
}

void I2C_Stop(void)
{
    CLR_BIT(PIR1, SSPIF);
    SET_BIT(SSPCON2, PEN);
    while (!GET_BIT(PIR1, SSPIF));
    CLR_BIT(PIR1, SSPIF);
}

void I2C_RepeatedStart(void)
{
    CLR_BIT(PIR1, SSPIF);
    SET_BIT(SSPCON2, RSEN);
    while (!GET_BIT(PIR1, SSPIF));
    CLR_BIT(PIR1, SSPIF);
}

u8 I2C_WriteByte(u8 Data)
{
    CLR_BIT(PIR1, SSPIF);
    SSPBUF = Data;
    while (!GET_BIT(PIR1, SSPIF));
    CLR_BIT(PIR1, SSPIF);
    return GET_BIT(SSPCON2, ACKSTAT); /* 0 = ACK received, 1 = NACK */
}

u8 I2C_ReadByte(u8 SendACK)
{
    u8 Data;
    CLR_BIT(PIR1, SSPIF);
    SET_BIT(SSPCON2, RCEN);
    while (!GET_BIT(PIR1, SSPIF));
    CLR_BIT(PIR1, SSPIF);
    Data = SSPBUF;

    /* Send ACK or NACK */
    if (SendACK)
        CLR_BIT(SSPCON2, ACKDT);
    else
        SET_BIT(SSPCON2, ACKDT);

    SET_BIT(SSPCON2, ACKEN);
    while (GET_BIT(SSPCON2, ACKEN));

    return Data;
}
