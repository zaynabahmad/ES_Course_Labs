#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

/*
 * PIC16F877A  –  MSSP module in SPI Master mode
 *
 * Hardware pins (fixed by silicon):
 *   RC5  = SDO  (MOSI)  – output
 *   RC4  = SDI  (MISO)  – input
 *   RC3  = SCK          – output in master mode
 *   Any GPIO = SS (CS)  – controlled manually (configured in SPI_config.h)
 */

/* ── SSPBUF – SPI Shift Buffer          (Bank 0: 0x13) ── */
#define SSPBUF          (*(volatile u8*)0x13)

/* ── SSPCON – SSP Control Register      (Bank 0: 0x14) ── */
#define SSPCON          (*(volatile u8*)0x14)
#define SSPCON_SSPEN     5   /* SSP Enable                          */
#define SSPCON_CKP       4   /* Clock Polarity  (0=idle low)        */
#define SSPCON_SSPM3     3   /* SPI Mode bits [3:0]                 */
#define SSPCON_SSPM2     2
#define SSPCON_SSPM1     1
#define SSPCON_SSPM0     0

/* ── SSPSTAT – SSP Status Register      (Bank 1: 0x94) ── */
#define SSPSTAT         (*(volatile u8*)0x94)
#define SSPSTAT_BF       0   /* Buffer Full flag (1 = transfer complete) */
#define SSPSTAT_CKE      6   /* Clock Edge select (1=active→idle)        */
#define SSPSTAT_SMP      7   /* Sample bit (0=middle, 1=end of output)   */

/* ── TRISC – Port C direction           (Bank 1: 0x87) ── */
#define TRISC           (*(volatile u8*)0x87)
#define TRISC3           3   /* SCK  → output in master */
#define TRISC4           4   /* SDI  → always input     */
#define TRISC5           5   /* SDO  → output           */

/* ── SSPCON SSPM[3:0] values for SPI Master ── */
#define SPI_MASTER_FOSC_4    0x00   /* Fosc/4   = 2 MHz  @ 8 MHz  */
#define SPI_MASTER_FOSC_16   0x01   /* Fosc/16  = 500 kHz         */
#define SPI_MASTER_FOSC_64   0x02   /* Fosc/64  = 125 kHz         */
#define SPI_MASTER_TMR2      0x03   /* Timer2 / 2 output          */

#endif /* SPI_PRIVATE_H */
