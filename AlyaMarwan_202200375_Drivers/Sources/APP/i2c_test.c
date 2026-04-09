#include "i2c.h"
#include "led.h"

extern int I2C_WriteData;

void I2C_Test(void)
{
    I2C_Init();
    LED_Init();

    while(1)
    {
        I2C_Start();

        I2C_WriteData = 0xA0;
        I2C_Write();

        I2C_WriteData = 0x55;
        I2C_Write();

        I2C_Stop();

        LED_Toggle();
        Delay_ms(500);
    }
}