#include "../MCAL/I2C/I2C_interface.h"

void I2C_Test()
{
    I2C_Init();

    while (1)
    {
        I2C_Start();
        I2C_Write(0x50); // example address
        I2C_Write('A');  // send data
        I2C_Stop();
    }
}