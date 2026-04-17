#include "../MCAL/SPI/SPI_Interface.h"

void SPI_Test(void)
{
    u8 receivedData = 0;

    SPI_Init();

    SPI_SelectSlave();
    receivedData = SPI_Transceive(0xAB);   /* Send 0xAB, receive reply */
    SPI_DeselectSlave();
}
