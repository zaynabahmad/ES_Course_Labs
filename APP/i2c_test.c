#include "app_tests.h"
#include "../MCAL/I2C/I2C_Interface.h"

static I2C_ConfigType APP_I2C_Config = {100000UL};

void APP_I2C_Test(void)
{
    I2C_Init(&APP_I2C_Config);
    I2C_MasterStart();
    I2C_MasterWriteByte(0xA0);
    I2C_MasterWriteByte(0x00);
    I2C_MasterStop();
}
