/**
 * @file    I2C_private.h
 * @brief   Register map and timing constants for the MSSP I2C driver.
 *
 * @details Master I2C drives one event per call -- start, stop, write, read,
 *          ack -- and each completes by raising SSPIF. The bit positions of
 *          those event triggers in SSPCON2 are named here so the driver body
 *          stays free of magic numbers.
 */
#ifndef I2C_PRIVATE_H
#define I2C_PRIVATE_H

#include "../SERVICES/Types.h"

#define I2C_REG_SSPCON      ( *((volatile byte_t *)0x14u) )
#define I2C_REG_SSPCON2     ( *((volatile byte_t *)0x91u) )
#define I2C_REG_SSPSTAT     ( *((volatile byte_t *)0x94u) )
#define I2C_REG_SSPADD      ( *((volatile byte_t *)0x93u) )
#define I2C_REG_SSPBUF      ( *((volatile byte_t *)0x13u) )
#define I2C_REG_PIR1        ( *((volatile byte_t *)0x0Cu) )
#define I2C_REG_TRISC       ( *((volatile byte_t *)0x87u) )

/* SCL = RC3, SDA = RC4 -- both released to the peripheral as inputs. */
#define I2C_PIN_SCL         3u
#define I2C_PIN_SDA         4u

/* SSPCON: enable bit; SSPM3:0 = 1000 selects I2C master mode. */
#define I2C_BIT_SSPEN       5u
#define I2C_MODE_MASTER     0x08u

/* SSPCON2 event-trigger bits. */
#define I2C_BIT_SEN         0u          /* start condition                  */
#define I2C_BIT_RSEN        1u          /* repeated start                   */
#define I2C_BIT_PEN         2u          /* stop condition                   */
#define I2C_BIT_RCEN        3u          /* enable master receive            */
#define I2C_BIT_ACKEN       4u          /* send the acknowledge sequence    */
#define I2C_BIT_ACKDT       5u          /* ack data: 0 = ACK, 1 = NACK      */
#define I2C_BIT_ACKSTAT     6u          /* ack received from slave (0 = ACK)*/

/* PIR1: SSPIF rises when the current I2C event finishes. */
#define I2C_BIT_SSPIF       3u

/* SSPADD = Fosc / (4 * Fscl) - 1; Fosc kept here for that solve. */
#define I2C_FOSC_HZ         20000000uL

#endif /* I2C_PRIVATE_H */
