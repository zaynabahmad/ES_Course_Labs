#include "../MCAL/I2C/I2C_interface.h"

void I2C_Test(void)
{
    I2C_voidInit();

    while(1)
    {
        I2C_voidStart();

        I2C_voidWrite(0xA0); // slave address+write
        I2C_voidWrite(0x55); // data

        I2C_voidStop();
    }
}