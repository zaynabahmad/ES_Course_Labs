#include "APP_Tests.h"
#include "../MCAL/I2C/I2C_Interface.h"

void APP_Test_I2C(void)
{
    /* Initialize I2C Master at 100kHz */
    I2C_Master_Init(100000);

    while(1)
    {
        I2C_Start();
        I2C_Write(0xA0); // Dummy slave address (write mode)
        I2C_Write(0xFF); // Dummy data
        I2C_Stop();

        for(volatile u16 i = 0; i < 30000; i++); // Delay
    }
}
