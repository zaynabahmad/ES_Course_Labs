#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

/*
 * PIC16F877A SPI — uses the MSSP (Master Synchronous Serial Port) module
 *
 * SPI pins (PORTC):
 *   RC3 — SCK  (clock)        → output in master mode
 *   RC4 — SDI  (MISO)         → input
 *   RC5 — SDO  (MOSI)         → output
 *
 * Chip-select (CS) is managed by the application via GPIO.
 */

/* MSSP registers shared with I2C */
#ifndef SSPBUF
#define SSPBUF      (*(volatile u8*)0x13)   /* SSP buffer / data register */
#endif

#ifndef SSPCON
#define SSPCON      (*(volatile u8*)0x14)   /* SSP control register 1     */
#endif

#ifndef SSPSTAT
#define SSPSTAT     (*(volatile u8*)0x94)   /* SSP status register        */
#endif

/* PIR1 — shared */
#ifndef PIR1
#define PIR1        (*(volatile u8*)0x0C)
#endif

/* ================= SSPCON bit positions ================= */
#define SSPEN_BIT   5   /* SSP enable */
#define CKP_BIT     4   /* Clock polarity: 0=idle low, 1=idle high */

/*
 * SSPM bits 3:0 — SPI mode
 *   0000 = SPI master, Fosc/4
 *   0001 = SPI master, Fosc/16
 *   0010 = SPI master, Fosc/64
 *   0011 = SPI master, TMR2 output / 2
 *   0100 = SPI slave,  SS pin controlled
 *   0101 = SPI slave,  SS disabled
 */
#define SPI_MASTER_FOSC4    0x00
#define SPI_MASTER_FOSC16   0x01
#define SPI_MASTER_FOSC64   0x02
#define SPI_SLAVE_SS_EN     0x04
#define SPI_SLAVE_SS_DIS    0x05

#define SSPM_MASK           0x0F

/* ================= SSPSTAT bit positions ================= */
#define SMP_BIT     7   /* Sample: 0=middle of data, 1=end of data */
#define CKE_BIT     6   /* Clock edge: 1=active-to-idle, 0=idle-to-active */
#define BF_BIT      0   /* Buffer full (receive complete) */

/* ================= PIR1 bit positions (SSP) ================= */
#define SSPIF_BIT   3   /* SSP interrupt flag */

#endif