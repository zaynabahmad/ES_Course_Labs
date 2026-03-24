#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

/* ── MSSP Registers (shared with I2C hardware) ── */
#define SSPBUF      (*(volatile u8*)0x13)   /* SPI Receive/Transmit Buffer  */
#define SSPCON      (*(volatile u8*)0x14)   /* SSP Control Register         */
#define SSPSTAT     (*(volatile u8*)0x94)   /* SSP Status Register          */

/* ── SSPCON bits ── */
#define SSPCON_SSPEN    5   /* SSP Enable                   */
#define SSPCON_WCOL     7   /* Write Collision               */
#define SSPCON_CKP      4   /* Clock Polarity               */

/* ── SSPSTAT bits ── */
#define SSPSTAT_BF      0   /* Buffer Full (byte received)  */
#define SSPSTAT_CKE     6   /* Clock Edge Select            */
#define SSPSTAT_SMP     7   /* Sample bit (0=middle,1=end)  */

/* ── TRISC / TRISA for SPI pins ── */
#define TRISC       (*(volatile u8*)0x87)
#define TRISC3      3       /* SCK  → RC3 (output in master)*/
#define TRISC4      4       /* SDI  → RC4 (always input)    */
#define TRISC5      5       /* SDO  → RC5 (output in master)*/

/* ── SS pin (chip select) — user controls via GPIO ── */
/* Define your CS pin in SPI_config.h                  */

#endif
