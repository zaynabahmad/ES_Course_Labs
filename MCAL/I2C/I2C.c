#include "I2C_Interface.h"

void I2C_Init(void)
{
    SSPCON = 0x28;
    
    SSPADD = 9;
    
    SSPSTAT = 0x80;
}

void I2C_Start(void)
{
    SET_BIT(SSPCON2, SEN);
    
    while(GET_BIT(SSPCON2, SEN));
}

void I2C_Stop(void)
{
    SET_BIT(SSPCON2, PEN);
    
    while(GET_BIT(SSPCON2, PEN));
}

void I2C_Restart(void)
{
    SET_BIT(SSPCON2, RSEN);
    
    while(GET_BIT(SSPCON2, RSEN));
}

void I2C_Write(u8 Data)
{
    SSPBUF = Data;
    
    while(GET_BIT(SSPSTAT, BF));
    
    while(GET_BIT(SSPSTAT, R_W));
}

u8 I2C_Read(u8 Ack)
{
    u8 data;
    
    SET_BIT(SSPCON2, RCEN);
    
    while(!GET_BIT(SSPSTAT, BF));
    
    data = SSPBUF;
    
    if(Ack == 0)
    {
        CLR_BIT(SSPCON2, ACKDT);
    }
    else
    {
        SET_BIT(SSPCON2, ACKDT);
    }
    
    SET_BIT(SSPCON2, ACKEN);
    
    while(GET_BIT(SSPCON2, ACKEN));
    
    return data;
}

u8 I2C_GetAckStatus(void)
{
    return GET_BIT(SSPCON2, ACKSTAT);
}
