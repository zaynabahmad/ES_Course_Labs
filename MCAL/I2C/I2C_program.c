#include "I2C_interface.h"
#include "I2C_private.h"
#include "I2C_config.h"

#include "../../SERVICES/BIT_MATH.h"

void I2C_Init(void)
{
    SET_BIT(TRISC, 3);
    SET_BIT(TRISC, 4);

    SSPCON = 0x28;

    SSPADD = 19;

    SSPSTAT = 0x00;

    SET_BIT(SSPCON, SSPEN);
}

void I2C_Start(void)
{
    SET_BIT(SSPCON2, SEN);
    while (GET_BIT(SSPCON2, SEN));
}

void I2C_Stop(void)
{
    SET_BIT(SSPCON2, PEN);
    while (GET_BIT(SSPCON2, PEN));
}

void I2C_Write(u8 byte)
{
    SSPBUF = byte;

    while (!GET_BIT(PIR1, SSPIF));
    CLR_BIT(PIR1, SSPIF);
}

u8 I2C_Read(u8 ack)
{
    u8 received;

    SET_BIT(SSPCON2, RCEN);
    while (!GET_BIT(PIR1, SSPIF));

    received = SSPBUF;
    CLR_BIT(PIR1, SSPIF);

    if (ack)
        CLR_BIT(SSPCON2, ACKDT);
    else
        SET_BIT(SSPCON2, ACKDT);

    SET_BIT(SSPCON2, ACKEN);
    while (GET_BIT(SSPCON2, ACKEN));

    return received;
}