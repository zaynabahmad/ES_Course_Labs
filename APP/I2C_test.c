#include "../SERVICES/STD_TYPES.h"
#include "../SERVICES/BIT_MATH.h"
#include "../MCAL/I2C/I2C_interface.h"


void APP_voidI2CTest(void)
{
    I2C_voidMasterInit();

    I2C_voidStart();
    I2C_u8WriteByte(0x42);
    I2C_u8WriteByte(0x52);
    I2C_voidStop();

    while(1)
    {
    }
}