#ifndef I2C_CONFIG_H
#define I2C_CONFIG_H

/* -------------------------------------------------------
 * CPU Frequency
 * ------------------------------------------------------- */
#define FOSC    4000000UL

/* -------------------------------------------------------
 * Mode Select
 * Uncomment exactly one of the two lines below.
 * ------------------------------------------------------- */
#define I2C_MASTER
//#define I2C_SLAVE

/* -------------------------------------------------------
 * Baud Rate — Master Mode only
 * Common values : 100000UL (Standard-mode, 100 kHz)
 *                 400000UL (Fast-mode,     400 kHz)
 * Formula       : SSPADD = FOSC / (4 * BaudRate) - 1
 * ------------------------------------------------------- */
#define I2C_BAUD_RATE   100000UL

/* -------------------------------------------------------
 * Slave Address — Slave Mode only (7-bit value)
 * Written to SSPADD<7:1>; the driver shifts it left by 1.
 * ------------------------------------------------------- */
#define I2C_SLAVE_ADDRESS   0x42

/* -------------------------------------------------------
 * Slave Address Width — Slave Mode only
 * Options : I2C_SLAVE_7BIT | I2C_SLAVE_10BIT
 * ------------------------------------------------------- */
#define I2C_SLAVE_ADDR_MODE     I2C_SLAVE_7BIT

/* -------------------------------------------------------
 * Clock Stretching — Slave Mode only
 * 1 → Enable  (SCL held LOW until CKP is released in ISR)
 * 0 → Disable
 * ------------------------------------------------------- */
#define I2C_CLOCK_STRETCH_EN    1

#endif
