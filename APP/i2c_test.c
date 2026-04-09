#include "../SERVICES/STD_TYPES.h"
#include "../MCAL/I2C/I2C_interface.h"

void I2C_Test(void) {
    I2C_voidInitMaster();

    I2C_voidStart();
    /* Send Slave Address + Write Bit (0x42 as per Slide 62) */
    I2C_u8Write(0x42);
    /* Send Data */
    I2C_u8Write(0x52);
    I2C_voidStop();
}