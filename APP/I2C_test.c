#include "../SERVICES/STD_TYPES.h"
#include "../MCAL/I2C/I2C_interface.h"

void APP_vidI2cTest(void) {
    I2C_Init(100000); // 100kHz

    /* Simulate writing 0x55 to an EEPROM at address 0xA0 */
    I2C_Start();
    I2C_Write(0xA0); // Slave Address + Write
    I2C_Write(0x00); // Memory Location
    I2C_Write(0x55); // Data
    I2C_Stop();

    while(1);
}