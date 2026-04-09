#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "I2C_private.h"
#include "I2C_interface.h"

void I2C_voidInit(void)
{
    // Enable I2C
    SET_BIT(SSPCON2,5);
}

void I2C_voidStart(void)
{
    SET_BIT(SSPCON2,0);
}

void I2C_voidStop(void)
{
    SET_BIT(SSPCON2,2);
}

void I2C_voidWrite(unsigned char data)
{
    SSPBUF = data;
}