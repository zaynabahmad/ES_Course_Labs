#include "SPI_Interface.h"
void SPI_Init(void) {
    unsigned char clock_divider = FOSC / (2 * SPI_CLOCK_RATE);
    // Set SPI Master/Slave mode
    if (SPI_MASTER_MODE == 0) {
        SSPCON |= (1 << SSPM0); // Master mode
    } else {
        SSPCON &= ~(1 << SSPM0); // Slave mode
    }
    
    // Set SPI Clock Rate
    SSPCON = (SSPCON & 0xF0) | (clock_divider & 0x0F);
    
    // Set SPI Mode
    switch (SPI_MODE) {
        case 0:
            SSPSTAT &= ~((1 << CKP) | (1 << BF)); // Mode 0
            break;
        case 1:
            SSPSTAT |= (1 << CKP); // Mode 1
            break;
        case 2:
            SSPSTAT |= (1 << BF); // Mode 2
            break;
        case 3:
            SSPSTAT |= ((1 << CKP) | (1 << BF)); // Mode 3
            break;
    }
    
    // Set Data Order
    if (SPI_DATA_ORDER == 0) {
        SSPSTAT &= ~(1 << BF); // MSB first
    } else {
        SSPSTAT |= (1 << BF); // LSB first
    }
    // Enable SPI Peripheral Interrupt
    PIE1 |= (1 << SSPIE); 
    
    // Enable Global and Peripheral Interrupts
    INTCON |= (1 << GIE) | (1 << PEIE);

    // Enable SPI
    SSPCON |= (1 << SSPEN);
}

void SPI_Write(unsigned char wr_data) {
    // Check if the buffer is currently empty before writing
    while (GET_BIT(SSPSTAT, BF));
    // Otherwise, we just write and let the ISR handle the completion
    SSPBUF = wr_data; 
}

unsigned char SPI_Read(void) {
    return SSPBUF; // Return received data
}

void SPI_Transmit(unsigned char tx_data) {
    SPI_Write(tx_data); // Transmit data using SPI_Write
}

unsigned char SPI_Receive(void) {
    return SPI_Read(); // Receive data using SPI_Read
}
