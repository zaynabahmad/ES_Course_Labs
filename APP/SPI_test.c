#include "../SERVICES/STD_TYPES.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/SPI/SPI_interface.h"

void APP_SPI_Test(void) 
{
    uint8 received_data = 0;

    /* 1. Setup Pin Directions */
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN3, GPIO_OUTPUT); /* SCK */
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN4, GPIO_INPUT);  /* SDI */
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN5, GPIO_OUTPUT); /* SDO */

    /* 2. Initialize as Master */
    SPI_Master_Init();

    while(1) 
    {
        /* Exchange data (Send 0x55, receive whatever the slave sends) */
        received_data = SPI_Exchange(0x55);
        (void)received_data;
        /* Small delay */
        Delay_ms(500);
    }
}
#ifndef Delay_ms
  #define Delay_ms(x)  // Dummy macro for GCC syntax check
#endif
#ifndef Delay_us
  #define Delay_us(x)  // Dummy macro for GCC syntax check
#endif