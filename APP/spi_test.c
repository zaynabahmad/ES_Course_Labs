#include "../SERVICES/STD_TYPES.h"
#include "../MCAL/SPI/SPI_Interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../HAL/LED/LED_interface.h"

void SPI_Test(void)
{
    GPIO_Init();
    LED_Init(GPIO_PORTB, GPIO_PIN0);
    
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN5, GPIO_OUTPUT);
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN4, GPIO_INPUT);
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN3, GPIO_OUTPUT);
    GPIO_SetPinDirection(GPIO_PORTA, GPIO_PIN5, GPIO_OUTPUT);
    
    SPI_Init(SPI_MASTER_FOSC_16);
    
    u8 received_data = 0;
    
    while(1)
    {
        GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN5, GPIO_LOW);
        
        received_data = SPI_Transceive(0xAA);
        
        GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN5, GPIO_HIGH);
        
        if(received_data == 0xAA)
        {
            LED_On(GPIO_PORTB, GPIO_PIN0);
        }
        else
        {
            LED_Off(GPIO_PORTB, GPIO_PIN0);
        }
        
        for(u32 i = 0; i < 10000; i++);
    }
}
