#include "SPI_interface.h"

void SPI_Init(void)
{
    TRISC3_bit = 0; // SDO output
    TRISC4_bit = 1; // SDI input
    TRISC5_bit = 0; // SCK output

    SSPSTAT = 0x00;
    SSPCON = 0x21; // Master mode, Fosc/16
}

char SPI_Transmit(char d)
{
    SSPBUF = d;
    while(!SSPIF_bit);
    SSPIF_bit = 0;
    return SSPBUF;
}