#include "../MCAL/I2C/I2C_interface.h"
void I2C_test(void) {
    I2C_voidMasterInit();
    while(1) {
        I2C_voidMasterStart();
        I2C_voidMasterWrite(0xA0); // Example Address
        I2C_voidMasterStop();
        Delay_ms(100);
    }
}