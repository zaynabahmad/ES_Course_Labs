#include "D:/ES-Project-Lab/SERVICES/std_types.h"
#include "D:/ES-Project-Lab/MCAL/GPIO/gpio.h"
#include "D:/ES-Project-Lab/MCAL/I2C/i2c_interface.h"
#include "D:\ES-Project-Lab\HAL\led_interface.h"
void app_i2c_test(void)
{
    u8 ackStatus = 0;
    u16 delayValue = 0;

    GPIO_setPinDirection(GPIO_PORTD, GPIO_PIN0, GPIO_OUTPUT);

    I2C_Init();

    while(1)
    {
        I2C_Start();

        /* 0xA0 = EEPROM address + write bit */
        ackStatus = I2C_Write(0xA0);

        if(ackStatus == 0)
        {
            I2C_Write(0x00);
            I2C_Write(0x55);
            LED_On(GPIO_PORTD, GPIO_PIN0);
        }
        else
        {
          LED_Off(GPIO_PORTD, GPIO_PIN0);
        }

        I2C_Stop();

        for(delayValue = 0; delayValue < 10000; delayValue++)
        {
            ;
        }
    }
}