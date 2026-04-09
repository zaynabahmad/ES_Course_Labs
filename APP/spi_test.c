#include "SPI_interface.h"

void SPI_Test(void)
{
    unsigned char data;

    SPI_voidInit();

    while(1)
    {
        data = SPI_u8Transfer('A'); // send A
    }
}