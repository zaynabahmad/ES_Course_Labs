#include "I2C_Interface.h"
void I2C_Init(u32 feq) {
    // Set I2C Master Mode
    SSPCON = 0x28;        // SSPEN enabled, I2C Master mode
    SSPCON2 = 0x00;
    
    // Set Clock (e.g., 100kHz)
    SSPADD = (8000000 / (4 * feq)) - 1;
    SSPSTAT = 0x00;

    // Enable Interrupts
    SET_BIT(PIE1, SSPIE);
    SET_BIT(INTCON, GIE);
    SET_BIT(INTCON, PEIE);
}

void I2C_Master_Start(void) {
    SET_BIT(SSPCON2, SEN); // Generate Start Condition
    // The Interrupt Manager will fire when the Start bit is finished
}

void I2C_Master_Stop(void) {
    SET_BIT(SSPCON2, PEN); // Generate Stop Condition
}

void I2C_Write_Byte(u8 wr_data) {
    SSPBUF = wr_data;        // Load data to buffer
}