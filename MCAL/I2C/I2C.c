#include "I2C_Interface.h"
#include "I2C_Private.h"
#include "I2C_Config.h"
#include "../../SERVICES/BIT_MATH.h"

/* Registers */
#define SSPCON   *((volatile u8*)0x14)
#define SSPCON2  *((volatile u8*)0x91)
#define SSPSTAT  *((volatile u8*)0x94)
#define SSPADD   *((volatile u8*)0x93)
#define SSPBUF   *((volatile u8*)0x13)

/* ============================= */

void I2C_Init(void)
{
    /* Master mode */
    SSPCON = 0b00101000;

    /* Clock = Fosc / (4 * (SSPADD + 1)) */
    SSPADD = 9;  // ~100kHz for 4MHz

    /* Enable module */
    SET_BIT(SSPCON , 5);
}

/* ============================= */

void I2C_Start(void)
{
    SET_BIT(SSPCON2 , SEN);
    while(GET_BIT(SSPCON2 , SEN));
}

/* ============================= */

void I2C_Stop(void)
{
    SET_BIT(SSPCON2 , PEN);
    while(GET_BIT(SSPCON2 , PEN));
}

/* ============================= */

void I2C_Write(u8 data)
{
    SSPBUF = data;
    while(!GET_BIT(SSPSTAT , BF));
}

/* ============================= */

u8 I2C_Read(u8 ack)
{
    u8 data;

    SET_BIT(SSPCON2 , 3); // RCEN

    while(!GET_BIT(SSPSTAT , BF));

    data = SSPBUF;

    if(ack)
        CLR_BIT(SSPCON2 , ACKDT);
    else
        SET_BIT(SSPCON2 , ACKDT);

    SET_BIT(SSPCON2 , ACKEN);
    while(GET_BIT(SSPCON2 , ACKEN));

    return data;
}