#include "I2C_private.h"

// Initialize I2C
void I2C_Init()
{
    // Set bitrate (simple value)
    TWBR = 2;
}

// Start condition
void I2C_Start()
{
    TWCR = (1 << 7) | (1 << 5) | (1 << 2);

    while (!(TWCR & (1 << 7)));
}

// Stop condition
void I2C_Stop()
{
    TWCR = (1 << 7) | (1 << 4) | (1 << 2);
}

// Write data
void I2C_Write(char data)
{
    TWDR = data;
    TWCR = (1 << 7) | (1 << 2);

    while (!(TWCR & (1 << 7)));
}