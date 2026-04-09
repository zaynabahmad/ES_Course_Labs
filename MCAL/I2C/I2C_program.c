#include "I2C_interface.h"
#include "I2C_private.h"
#include "I2C_config.h"

#include "../../SERVICES/BIT_MATH.h"

#define _XTAL_FREQ 8000000

void I2C_Init(void)
{
    /* Set pins as input */
    SET_BIT(TRISC, 3); // SCL
    SET_BIT(TRISC, 4); // SDA

    /* Enable I2C Master mode */
    SSPCON = 0x28;  // I2C Master mode

    /* Set clock */
    SSPADD = (_XTAL_FREQ / (4 * I2C_CLOCK)) - 1;
}

void I2C_Start(void)
{
    SET_BIT(SSPCON2, 0); // SEN
    while(GET_BIT(SSPCON2, 0));
}

void I2C_Stop(void)
{
    SET_BIT(SSPCON2, 2); // PEN
    while(GET_BIT(SSPCON2, 2));
}

void I2C_Write(u8 data)
{
    SSPBUF = data;

    while(!GET_BIT(PIR1, 3)); // SSPIF
    CLR_BIT(PIR1, 3);
}

u8 I2C_Read(u8 ack)
{
    u8 data;

    SET_BIT(SSPCON2, 3); // RCEN
    while(!GET_BIT(SSPSTAT, 0));

    data = SSPBUF;

    /* Send ACK/NACK */
    if(ack)
        CLR_BIT(SSPCON2, 5); // ACKDT = 0
    else
        SET_BIT(SSPCON2, 5); // ACKDT = 1

    SET_BIT(SSPCON2, 4); // ACKEN
    while(GET_BIT(SSPCON2, 4));

    return data;
}