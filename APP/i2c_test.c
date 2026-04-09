#include "I2C_Interface.h"

void i2c_test_run(void) {
    I2C_Master_Init(100000);
    I2C_Master_Start();
    I2C_Master_Write(0xA0);
    I2C_Master_Write(0x00);
    I2C_Master_Write(0xFF);
    I2C_Master_Stop();
}