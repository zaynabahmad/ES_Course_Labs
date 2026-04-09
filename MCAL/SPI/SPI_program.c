#include "SPI_private.h"

// Initialize SPI as Master
void SPI_InitMaster()
{
    // MOSI, SCK as output
    DDRB |= (1 << 5) | (1 << 7);

    // Enable SPI + Master + clk/16
    SPCR = (1 << 6) | (1 << 4) | (1 << 0);
}

// Send & receive
char SPI_Transfer(char data)
{
    SPDR = data;

    // Wait until done
    while (!(SPSR & (1 << 7)));

    return SPDR;
}