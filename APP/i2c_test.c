#include "../SERVICES/STD_TYPES.h"
#include "../MCAL/I2C/I2C_Interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../HAL/LED/LED_interface.h"

#define EEPROM_ADDRESS 0xA0

void I2C_Test(void)
{
    GPIO_Init();
    LED_Init(GPIO_PORTB, GPIO_PIN0);
    
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN3, GPIO_OUTPUT);
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN4, GPIO_OUTPUT);
    
    I2C_Init();
    
    u8 write_data = 0x55;
    u8 read_data = 0;
    
    while(1)
    {
        I2C_Start();
        I2C_Write(EEPROM_ADDRESS | I2C_WRITE);
        
        if(I2C_GetAckStatus() == 0)
        {
            I2C_Write(0x00);
            I2C_Write(write_data);
            I2C_Stop();
            
            for(u32 i = 0; i < 10000; i++);
            
            I2C_Start();
            I2C_Write(EEPROM_ADDRESS | I2C_WRITE);
            I2C_Write(0x00);
            
            I2C_Restart();
            I2C_Write(EEPROM_ADDRESS | I2C_READ);
            
            read_data = I2C_Read(1);
            I2C_Stop();
            
            if(read_data == write_data)
            {
                LED_On(GPIO_PORTB, GPIO_PIN0);
            }
            else
            {
                LED_Off(GPIO_PORTB, GPIO_PIN0);
            }
        }
        
        for(u32 i = 0; i < 50000; i++);
    }
}
