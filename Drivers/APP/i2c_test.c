#include "../../APP/app_interface.h"
#include "../../MCAL/I2C/I2C_interface.h"


void APP_I2C_Test(void) {
    I2C_voidInitMaster(100000);
    
    while(1) {
        I2C_voidStart();
        I2C_voidWrite(0xA0);  // Example slave address
        I2C_voidWrite('X');
        I2C_voidStop();
        Delay_ms(200);
    }
}