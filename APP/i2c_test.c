#include "D:\Uni\Y4 S2\Embedded Systems\Final\MCAL\I2C\I2C_interface.h"

void I2C_Test(void)
{
    unsigned char status;

    I2C_voidInit();

    while (1)
    {
        I2C_voidStart();

        status = I2C_u8Write(0xA0);
        if (status == I2C_OK)
        {
            I2C_u8Write('M');
        }

        I2C_voidStop();
    }
}