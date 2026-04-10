// Purpose: 2-wire communication with multiple devices (sensors, EEPROM, RTC)
// Uses SDA (data) and SCL (clock) - only 2 wires for many devices!

#include "i2c.h"

void I2C_Init(uint32 clock_speed) {
    // For 100kHz at 8MHz
    SSPCON = 0x28;      // I2C master mode
    SSPADD = (_XTAL_FREQ / (4 * clock_speed)) - 1;
    SSPSTAT = 0x80;     // Slew rate disabled
    TRISCbits.TRISC3 = 1;  // SCL as input
    TRISCbits.TRISC4 = 1;  // SDA as input
}

void I2C_Start(void) {
    SEN = 1;            // Send start condition
    while(SEN);         // Wait for completion
}

void I2C_Stop(void) {
    PEN = 1;            // Send stop condition
    while(PEN);         // Wait for completion
}

void I2C_Write(uint8 data) {
    SSPBUF = data;      // Put data in buffer
    while(!SSPSTATbits.BF);  // Wait for send
}

uint8 I2C_Read(uint8 ack) {
    RCEN = 1;           // Enable receive
    while(!SSPSTATbits.BF);  // Wait for data
    if(!ack) {
        ACKDT = 1;      // Send NACK (no more data)
    } else {
        ACKDT = 0;      // Send ACK (want more data)
    }
    ACKEN = 1;          // Send acknowledge
    while(ACKEN);       // Wait for completion
    return SSPBUF;      // Return received data
}