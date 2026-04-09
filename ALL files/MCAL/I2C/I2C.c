#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"

#include "I2C_Interface.h"
#include "I2C_Private.h"
#include "I2C_Config.h"

void I2C_Init(void)
{
    /* Set clock */
    SSPADD = (u8)((I2C_FOSC / (4UL * I2C_CLOCK)) - 1);

    /* Master mode */
    SSPCON = 0x28;

    /* Enable MSSP */
    SET_BIT(SSPCON, SSPEN);
}

void I2C_Start(void)
{
    SET_BIT(SSPCON, SEN);

    while(GET_BIT(SSPCON, SEN));   // wait
}

void I2C_Stop(void)
{
    SET_BIT(SSPCON, PEN);

    while(GET_BIT(SSPCON, PEN));   // wait
}

void I2C_Write(u8 Data)
{
    SSPBUF = Data;

    while(GET_BIT(SSPSTAT, BF));   // wait
}

u8 I2C_Read(void)
{
    /* Enable receive */
    SET_BIT(SSPCON, 3);  // RCEN

    while(!GET_BIT(SSPSTAT, BF));  // wait

    return SSPBUF;
}