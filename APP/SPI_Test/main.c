#include "../../MCAL/SPI/SPI_Interface.h"
#include "../../MCAL/GPIO/GPIO_interface.h"

void main(void)
{
    SPI_Init();

    while(1)
    {
        SPI_Transmit('A');

        for(u16 i = 0; i < 50000; i++); // delay
    }
}