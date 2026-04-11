#include "../../MCAL/I2C/I2C_Interface.h"

void main(void)
{
    I2C_Init();

    while(1)
    {
        I2C_Start();

        I2C_Write(0xA0);   // example address
        I2C_Write('A');

        I2C_Stop();

        for(u16 i = 0; i < 50000; i++);
    }
}