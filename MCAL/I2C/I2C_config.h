#ifndef I2C_CONFIG_H
#define I2C_CONFIG_H

// Microcontroller System Clock Frequency
#define I2C_FOSC         8000000UL

// Desired I2C Baud Rate (Standard Mode is 100 kHz)
#define I2C_BAUDRATE     100000UL

// The calculated value to load into SSPADD 
#define I2C_SSPADD_VAL   ((I2C_FOSC / (4 * I2C_BAUDRATE)) - 1)

#endif