/*#######################################################
Testing SPI
#######################################################*/


#include "../MCAL/SPI/SPI_Interface.h"
#include "../MCAL/GPIO/GPIO_Interface.h"

void SPI_Test(void)
{
    u8 txData = 0;
    u8 rxData;

    GPIO_SetPortDirection(GPIO_PORTD, 0x00);  
    GPIO_SetPinDirection(GPIO_PORTA, GPIO_PIN5, GPIO_OUTPUT);  

    SPI_Init();

    while(1)
    {
        GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN5, GPIO_LOW);

        rxData = SPI_Transfer(txData);

        GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN5, GPIO_HIGH);

        GPIO_SetPortValue(GPIO_PORTD, rxData);

        txData++;
        { volatile u16 d; for(d=0; d<30000; d++); }
    }
}
