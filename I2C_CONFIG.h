#ifndef I2C_CONFIG_H
#define I2C_CONFIG_H

/* Baud rate register value.
   Formula: SSPADD = (Fosc / (4 * freq_Hz)) - 1
   8 MHz Fosc, 100 kHz I2C -> SSPADD = (8000000/(4*100000)) - 1 = 19 */
#define I2C_SSPADD_VALUE   19

#endif
