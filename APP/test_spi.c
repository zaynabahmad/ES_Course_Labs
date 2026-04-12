#include "SPI_interface.h"

void test_SPI(void)
{
    char response;

    SPI_Init();

    response = SPI_Transfer(0xAB);

    /* in loopback mode, response should equal 0xAB */
    if (response == (char)0xAB)
    {
        /* pass */
    }
}
