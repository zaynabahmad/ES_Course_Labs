#include "../MCAL/I2C/I2C_Interface.h"

void I2C_Test(void)
{
    unsigned long i;

    I2C_Init();

    while(1)
    {
        I2C_Start();

        /* Example: send slave address (write mode) */
        I2C_Write(0xA0);

        /* Send data */
        I2C_Write(0x55);

        I2C_Stop();

        for(i = 0; i < 50000; i++);
    }
}