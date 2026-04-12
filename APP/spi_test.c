#include "../MCAL/SPI/SPI_interface.h"

void SPI_Test(void)
{
    /* Initialize SPI */
    SPI_Init();

    /* Send 0xAB and ignore response */
    (void)SPI_Transceive(0xAB);
}