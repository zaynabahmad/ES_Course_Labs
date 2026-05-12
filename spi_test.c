#include "spi_test.h"
#include "../MCAL/SPI_INTERFACE.h"

void SPI_Test_Init(void)
{
    SPI_Init();
}

void SPI_Test_Run(void)
{
    u8 response;

    /* Exchange a test byte with an SPI slave device */
    response = SPI_ExchangeByte(0xA5);

    /* Loopback check: if MISO is wired to MOSI, response should equal 0xA5 */
    (void)response;
}
