/*#######################################################
Testing I2C
#######################################################*/

#include "../MCAL/I2C/I2C_Interface.h"
#include "../MCAL/GPIO/GPIO_Interface.h"

void I2C_Test(void)
{
    u8 readData;

    GPIO_SetPortDirection(GPIO_PORTD, 0x00);  /* PORTD output */

    I2C_Master_Init();

    while(1)
    {
        /* Write EEPROM */
        I2C_Master_Start();
        I2C_Master_Write(0xA0);     /* EEPROM control byte */
        I2C_Master_Write(0x00);     
        I2C_Master_Write(0xAA);     
        I2C_Master_Stop();

        
        { volatile u16 d; for(d=0; d<30000; d++); }

        
        I2C_Master_Start();
        I2C_Master_Write(0xA0);     
        I2C_Master_Write(0x00);     
        I2C_Master_RepeatedStart();
        I2C_Master_Write(0xA1);     
        readData = I2C_Master_ReadNack();
        I2C_Master_Stop();

        GPIO_SetPortValue(GPIO_PORTD, readData);

        { volatile u16 d; for(d=0; d<60000; d++); }
    }
}
