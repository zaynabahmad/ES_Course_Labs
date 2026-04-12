#ifndef I2C_CONFIG_H
#define I2C_CONFIG_H

/* CPU Frequency */
#define FOSC    4000000UL

/* I2C Mode: I2C_MASTER or I2C_SLAVE */
#define I2C_MODE         I2C_MASTER

/* I2C Clock Frequency in Hz (Master mode) */
#define I2C_CLOCK_FREQ   100000UL    /* 100kHz Standard Mode */

/* Slave Address (used in Slave mode only, 7-bit) */
#define I2C_SLAVE_ADDRESS    0x48

#endif
