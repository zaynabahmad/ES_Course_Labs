#include "../MCAL/I2C/I2C_interface.h"
#include "i2c_test.h"

void I2C_Test(void)
{
    I2C_Init();

    I2C_Start();
    I2C_Write(0xA0);
    I2C_Write(0x00);
    I2C_Stop();
}