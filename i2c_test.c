#include "i2c_test.h"
#include "../MCAL/I2C_INTERFACE.h"

#define I2C_SLAVE_ADDR   0x50  /* Example: 24C02 EEPROM write address */

void I2C_Test_Init(void)
{
    I2C_Init();
}

void I2C_Test_Run(void)
{
    /* Write byte 0xAB to address 0x00 of an I2C EEPROM */
    I2C_Start();
    I2C_SendByte(I2C_SLAVE_ADDR);   /* Slave address + write bit */
    I2C_SendByte(0x00);             /* Memory address            */
    I2C_SendByte(0xAB);             /* Data byte                 */
    I2C_Stop();
}
