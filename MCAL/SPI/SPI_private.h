#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

/* ------- Registers ------- */
#define TRISC (*((volatile u8 *)0x87))
#define TRISA (*((volatile u8 *)0x85))
#define SSPBUF (*((volatile u8 *)0x13))
#define SSPCON (*((volatile u8 *)0x14))
#define SSPSTAT (*((volatile u8 *)0x94))
#define PORTA (*((volatile u8 *)0x05))

/* ------- SSPCON bits ------- */
#define SSPCON_SSPEN 5 /* SSP Enable             */
#define SSPCON_SSPM0 0 /* Mode bit 0             */
#define SSPCON_SSPM1 1 /* Mode bit 1             */
#define SSPCON_SSPM2 2 /* Mode bit 2             */
#define SSPCON_SSPM3 3 /* Mode bit 3             */
#define SSPCON_CKP 4   /* Clock Polarity         */

/* ------- SSPSTAT bits ------- */
#define SSPSTAT_BF 0  /* Buffer Full flag       */
#define SSPSTAT_CKE 6 /* Clock Edge Select      */
#define SSPSTAT_SMP 7 /* Sample bit             */

/* SS (Slave Select) on RA5 – change if needed */
#define SPI_SS_PORT PORTA
#define SPI_SS_TRIS TRISA
#define SPI_SS_PIN 5

#endif