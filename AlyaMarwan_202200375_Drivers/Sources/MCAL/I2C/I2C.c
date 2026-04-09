#include "i2c.h"
#include "bit_math.h"

int I2C_WriteData = 0;
int I2C_AckBit    = 0;
int I2C_ReadData  = 0;

void I2C_Init(void)
{
    SET_BIT(TRISC, 3);
    SET_BIT(TRISC, 4);
    SSPADD  = 19;
    SSPCON  = 0x28;
    SSPSTAT = 0x80;
}

void I2C_Start(void)
{
    SET_BIT(SSPCON2, 0);
    while(GET_BIT(SSPCON2, 0));
}

void I2C_Stop(void)
{
    SET_BIT(SSPCON2, 2);
    while(GET_BIT(SSPCON2, 2));
}

void I2C_Write(void)
{
    SSPBUF = I2C_WriteData;
    while(GET_BIT(SSPSTAT, 2));
    while(GET_BIT(SSPCON2, 3));
}

void I2C_Read(void)
{
    SET_BIT(SSPCON2, 3);
    while(GET_BIT(SSPCON2, 3));
    I2C_ReadData = SSPBUF;
    if(I2C_AckBit == 1)
        CLR_BIT(SSPCON2, 5);
    else
        SET_BIT(SSPCON2, 5);
    SET_BIT(SSPCON2, 4);
    while(GET_BIT(SSPCON2, 4));
}