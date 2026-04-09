#include "spi_test.h"
#include "../MCAL/SPI/SPI_interface.h"

void APP_SPI_Test(void)
{
    /* Variables declared at top for C89 compatibility */
    u8 received;
    volatile u16 d;

    SPI_MasterInit(SPI_MODE_0);

    while (1)
    {
        SPI_SS_Low();
        received = SPI_Transceive(0xAB); /* Send 0xAB, capture reply */
        SPI_SS_High();

        (void)received;

        for (d = 0; d < 50000; d++)
            ;
    }
}