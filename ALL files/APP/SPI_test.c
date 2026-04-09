#include "../MCAL/SPI/SPI_Interface.h"

void SPI_Test(void)
{
    u8 received;
    unsigned long i;   // ? moved here

    SPI_Init();

    while(1)
    {
        received = SPI_Transceive(0x55);

        for(i = 0; i < 50000; i++);   // delay
    }
}