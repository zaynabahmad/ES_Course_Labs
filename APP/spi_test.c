#include "../MCAL/SPI/SPI_interface.h"

void SPI_Test(void)
{
    u8 Local_ReceivedData = 0;

    /* Initialize SPI */
    SPI_Init();

    /* Send 0xAB and receive response */
    Local_ReceivedData = SPI_Transceive(0xAB);
}