#ifndef I2C_CONFIG_H
#define I2C_CONFIG_H

/* Define your CPU's oscillator frequency in Hz */
#ifndef FOSC
#define FOSC 4000000 
#endif

/* Desired I2C Clock Speed in Hz 
 * Standard Mode: 100000 (100 kHz)
 * Fast Mode:     400000 (400 kHz)
 */
#define I2C_CLOCK_SPEED   100000

/* Automatically calculate the SSPADD value for Master Mode
 * Formula: SSPADD = (FOSC / (4 * I2C_CLOCK)) - 1
 */
#define I2C_SSPADD_VALUE  ((FOSC / (4UL * I2C_CLOCK_SPEED)) - 1)

#endif