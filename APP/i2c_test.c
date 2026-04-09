#include "i2c_test.h"
#include "../MCAL/I2C/I2C_interface.h"

void APP_I2C_Test(void)
{
    /* Variables declared at top for C89 compatibility */
    volatile u16 d;

    I2C_MasterInit(100000UL); /* 100 kHz */

    while (1)
    {
        /* Write 0x55 to slave address 0x50 (e.g. EEPROM) */
        I2C_Start();
        I2C_WriteByte(0x50 << 1); /* Address + Write bit */
        I2C_WriteByte(0x00);      /* Register/address    */
        I2C_WriteByte(0x55);      /* Data                */
        I2C_Stop();

        for (d = 0; d < 50000; d++)
            ;
    }
}