/*
 * i2c.h
 * I2C (MSSP in I2C Master mode) Driver for PIC16F877A
 *
 * Pin mapping (fixed by hardware):
 *   SDA = RC4
 *   SCL = RC3
 *
 * Both pins need external pull-up resistors (typically 4.7 kΩ to VDD).
 *
 * Baud rate formula:
 *   SSPADD = (F_CPU / (4 * F_SCL)) - 1
 *   For F_CPU=8MHz, F_SCL=100kHz: SSPADD = (8000000/400000)-1 = 19
 */

#ifndef I2C_H
#define I2C_H

#include "../std_types.h"
#include <xc.h>

/* I2C status codes (SSPSTAT & SSPCON2 derived) */
#define I2C_ACK     0
#define I2C_NACK    1

/* Read/Write bit appended to 7-bit address */
#define I2C_WRITE   0
#define I2C_READ    1

void  I2C_init          (uint32 sclFreq);   /* e.g. 100000UL for 100 kHz */
void  I2C_start         (void);
void  I2C_repeatedStart (void);
void  I2C_stop          (void);
uint8 I2C_writeByte     (uint8 data);       /* Returns ACK(0) or NACK(1) */
uint8 I2C_readByteACK   (void);
uint8 I2C_readByteNACK  (void);

#endif /* I2C_H */
