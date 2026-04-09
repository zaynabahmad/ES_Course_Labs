#include "spi_test.h"
#include "../MCAL/SPI/SPI_interface.h"


void SPI_Test(void)
{
    char received;

    SPI_Init();

    // Example transmit
    received = SPI_Transmit(0x55); // Send 0x55
    received = SPI_Transmit(0xAA); // Send 0xAA

    // Infinite loop to hold MCU
    while(1);
}