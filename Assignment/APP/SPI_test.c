#include "../MCAL/SPI/SPI_interface.h"

void SPI_Test(void)
{
    SPI_voidInitMaster();

    u8 received;

    while(1)
    {
        received = SPI_u8SendReceive(0x55);
    }
}