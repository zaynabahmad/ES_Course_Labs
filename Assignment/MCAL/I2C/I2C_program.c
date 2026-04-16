#include "../SERVICES/STD_TYPES.h"
#include "../SERVICES/BIT_MATH.h"

#include "../MCAL/I2C/I2C_interface.h"
#include "../MCAL/I2C/I2C_private.h"
#include "../MCAL/I2C/I2C_config.h"

void I2C_voidInit(void)
{

    SSPCON1=0b00101000;

    // Clock=Fosc/(4*(SSPADD+1))
    SSPADD = 19;  // X if 100kHz & 8MHz

    //  MSSP
    SET_BIT(SSPCON1,SSPEN);
}

void I2C_voidStart(void)
{
    SET_BIT(SSPCON2,SEN);
    while(GET_BIT(SSPCON2,SEN));
}

void I2C_voidRepeatedStart(void)
{
    SET_BIT(SSPCON2,RSEN);
    while(GET_BIT(SSPCON2,RSEN));
}

void I2C_voidStop(void)
{
    SET_BIT(SSPCON2, PEN);
    while(GET_BIT(SSPCON2, PEN));
}

void I2C_voidWrite(u8 data)
{
    SSPBUF = data;
    while(GET_BIT(SSPSTAT, BF));
}

u8 I2C_u8Read_ACK(void)
{
    u8 data;

    SET_BIT(SSPCON2, RCEN);
    while(!GET_BIT(SSPSTAT, BF));

    data = SSPBUF;

    CLR_BIT(SSPCON2, ACKDT); // ACK
    SET_BIT(SSPCON2, ACKEN);

    return data;
}

u8 I2C_u8Read_NACK(void)
{
    u8 data;

    SET_BIT(SSPCON2, RCEN);
    while(!GET_BIT(SSPSTAT, BF));

    data = SSPBUF;

    SET_BIT(SSPCON2, ACKDT); // NACK
    SET_BIT(SSPCON2, ACKEN);

    return data;
}