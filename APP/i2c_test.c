#include "app_tests.h"

#include "../MCAL/I2C/I2C_Interface.h"

void APP_Test_I2C(void)
{
    I2C_MasterInit(100000UL);
    I2C_Start();
    (void)I2C_Write(0xA0U);
    I2C_Stop();
}
