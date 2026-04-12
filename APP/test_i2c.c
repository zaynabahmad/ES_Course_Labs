#include "I2C_interface.h"

#define EEPROM_ADDR    0x50
#define TEST_DATA      0x42

void test_I2C(void)
{
    char readback;

    I2C_Init();

    /* write 0x42 to address 0x00 */
    I2C_Start();
    I2C_Write((EEPROM_ADDR << 1) | 0);   /* write mode */
    I2C_Write(0x00);                      /* memory address */
    I2C_Write(TEST_DATA);
    I2C_Stop();

    /* read back from address 0x00 */
    I2C_Start();
    I2C_Write((EEPROM_ADDR << 1) | 0);
    I2C_Write(0x00);
    I2C_Start();
    I2C_Write((EEPROM_ADDR << 1) | 1);   /* read mode */
    readback = I2C_Read(I2C_NACK);
    I2C_Stop();

    /* readback should be TEST_DATA */
    (void)readback;
}
