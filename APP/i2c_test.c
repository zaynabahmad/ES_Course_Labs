#include "../SERVICES/STD_TYPES.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/I2C/I2C_interface.h"
#include "i2c_test.h"

// Simple delay to space out transmissions
static void APP_Delay(void)
{
    unsigned long i;
    for(i = 0; i < 100000; i++);
}

void APP_TestI2C(void)
{
    // Initialize GPIO
    GPIO_Init();

    // Initialize I2C Master
    I2C_Master_Init();

    // Send a packet every ~1 second
    while(1)
    {
        I2C_Start();
        
        // Send Slave Address + Write Bit (0x42)
        I2C_Write(0x42); 
        
        // Send Data (0x52) 
        I2C_Write(0x52); 
        
        I2C_Stop();
        
        APP_Delay();
    }
}