// Purpose: Tests I2C by talking to 24LC256 EEPROM
// Writes a byte, reads it back, verifies it works

#include "i2c.h"
#include "gpio.h"

#define EEPROM_ADDR 0xA0  // 24LC256 address

void I2C_Test(void) {
    uint8 write_data = 0x55;  // Data to write
    uint8 read_data;

    I2C_Init(100000);  // 100kHz I2C

    // Write to EEPROM
    I2C_Start();
    I2C_Write(EEPROM_ADDR);  // Send device address + write
    I2C_Write(0x00);         // High byte of memory address
    I2C_Write(0x00);         // Low byte of memory address
    I2C_Write(write_data);   // Data to write
    I2C_Stop();

    __delay_ms(10);  // Wait for EEPROM to write

    // Read from EEPROM
    I2C_Start();
    I2C_Write(EEPROM_ADDR);  // Send device address + write
    I2C_Write(0x00);         // High byte of memory address
    I2C_Write(0x00);         // Low byte of memory address
    I2C_Start();             // Repeated start
    I2C_Write(EEPROM_ADDR | 1);  // Send device address + read
    read_data = I2C_Read(0);      // Read data with NACK
    I2C_Stop();

    // Check if read matches write
    if(read_data == write_data) {
        // Blink LED fast - success!
        while(1) {
            GPIO_TogglePin(PORTB_ID, PIN0);
            __delay_ms(100);
        }
    }
}