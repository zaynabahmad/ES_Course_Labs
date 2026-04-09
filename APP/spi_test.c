#include "../MCAL/SPI/SPI_Interface.h"
#include "../MCAL/GPIO/GPIO_Interface.h"

/* Test: SPI master sends incrementing byte, reads response to PORTD */
void SPI_Test(void)
{
    u8 txData = 0;
    u8 rxData;

    GPIO_SetPortDirection(GPIO_PORTD, 0x00);  /* PORTD output for display */
    GPIO_SetPinDirection(GPIO_PORTA, GPIO_PIN5, GPIO_OUTPUT);  /* SS pin */

    SPI_Init();

    while(1)
    {
        /* Assert SS low */
        GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN5, GPIO_LOW);

        rxData = SPI_Transfer(txData);

        /* Deassert SS */
        GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN5, GPIO_HIGH);

        /* Display received data */
        GPIO_SetPortValue(GPIO_PORTD, rxData);

        txData++;
        { volatile u16 d; for(d=0; d<30000; d++); }
    }
}
