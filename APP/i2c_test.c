#include "../MCAL/I2C/I2C_interface.h"

void I2C_Test_voidInit(void) {
    I2C_voidInitMaster(100000);
}

void I2C_Test_voidRun(void) {
    I2C_voidStart();
    I2C_voidWrite(0xA0); // Example Address
    I2C_voidWrite(0x00); // Internal Reg
    I2C_voidStop();
}