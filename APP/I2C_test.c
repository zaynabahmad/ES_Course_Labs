#include "../SERVICES/STD_TYPES.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/I2C/I2C_interface.h"

void APP_I2C_Test(void) {
    /* 1. Setup Pin Directions (RC3 and RC4 as Inputs for I2C) */
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN3, GPIO_INPUT);
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN4, GPIO_INPUT);
    
    /* 2. Initialize I2C at 100kHz */
    I2C_Master_Init(100000);

    while(1) {
        /* Simple Write Sequence Example */
        I2C_Master_Start();
        I2C_Master_Write(0xA0); /* Fake Device Address */
        I2C_Master_Write(0x01); /* Fake Register Address */
        I2C_Master_Write(0x55); /* Data to write */
        I2C_Master_Stop();
        
        Delay_ms(1000);
    }
}
#ifndef Delay_ms
  #define Delay_ms(x)  // Dummy macro for GCC syntax check
#endif
#ifndef Delay_us
  #define Delay_us(x)  // Dummy macro for GCC syntax check
#endif