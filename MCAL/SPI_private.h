/**
 * @file    SPI_private.h
 * @brief   Register map and pin layout for the MSSP SPI driver.
 *
 * @details SPI on the PIC16F877A uses the MSSP block (SSPCON/SSPSTAT/SSPBUF)
 *          and four PORTC pins. The pin numbers are fixed by silicon, so they
 *          are constants here rather than configuration.
 */
#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

#include "../SERVICES/Types.h"

#define SPI_REG_SSPCON      ( *((volatile byte_t *)0x14u) )
#define SPI_REG_SSPSTAT     ( *((volatile byte_t *)0x94u) )
#define SPI_REG_SSPBUF      ( *((volatile byte_t *)0x13u) )
#define SPI_REG_PORTC       ( *((volatile byte_t *)0x07u) )
#define SPI_REG_TRISC       ( *((volatile byte_t *)0x87u) )

/* MSSP pins on PORTC fixed by the silicon. */
#define SPI_PIN_SCK         3u          /* serial clock   -- master output  */
#define SPI_PIN_SDI         4u          /* data in        -- input          */
#define SPI_PIN_SDO         5u          /* data out       -- master output  */

/* SSPCON bits. */
#define SPI_BIT_SSPEN       5u          /* synchronous serial port enable   */
#define SPI_BIT_CKP         4u          /* clock idle polarity (idle low)   */

/* SSPSTAT bits. */
#define SPI_BIT_CKE         6u          /* clock edge select                */
#define SPI_BIT_BF          0u          /* buffer-full / transfer-done flag */

#endif /* SPI_PRIVATE_H */
