#include "../../SERVICES/STD_TYPES.h"
#include "SPI_interface.h"

void SPI_Init(void)
{
    // SCK (RC3)  output
    TRISC3_bit = 0;

    // SDO (RC5)  output
    TRISC5_bit = 0;

    // SDI (RC4)  input
    TRISC4_bit = 1;

    // SSPSTAT: sample at middle, transmit on active to idle
    SSPSTAT = 0x40;

    // SSPCON:
    // Master mode, Fosc/16, enable SPI
    SSPCON = 0x21;  // 0010 0001
}

unsigned char SPI_Transfer (unsigned char u8Data)
{
    SSPBUF = u8Data;         // send data
    while(!SSPIF_bit);      // wait complete
    SSPIF_bit = 0;           // clear flag
    return SSPBUF;          // return received
}