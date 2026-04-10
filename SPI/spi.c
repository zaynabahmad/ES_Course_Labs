// Purpose: Fast communication between PIC and other chips (SD cards, displays, etc)
// Uses 4 wires: SCK (clock), MOSI (data out), MISO (data in), SS (select)

#include "spi.h"

void SPI_MasterInit(void) {
    // Set pins
    TRISCbits.TRISC3 = 0;  // SCK as output
    TRISCbits.TRISC5 = 0;  // SDO as output
    TRISCbits.TRISC4 = 1;  // SDI as input

    // Setup SPI module
    SSPSTAT = 0x40;  // Middle speed
    SSPCON = 0x20;   // Master mode, Fosc/4
}

void SPI_SlaveInit(void) {
    // Set pins
    TRISCbits.TRISC3 = 1;  // SCK as input
    TRISCbits.TRISC5 = 1;  // SDO as input
    TRISCbits.TRISC4 = 0;  // SDI as output

    // Setup SPI module
    SSPSTAT = 0x40;
    SSPCON = 0x20;   // Slave mode
}

uint8 SPI_Transfer(uint8 data) {
    SSPBUF = data;          // Send data
    while(!SSPSTATbits.BF); // Wait for receive
    return SSPBUF;          // Return received data
}