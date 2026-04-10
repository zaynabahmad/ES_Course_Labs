#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

/* Register Definitions for PIC16F877A - SPI */

/* SPI Control Registers */
#define SSPCON (*((volatile u8 *)0x14))  /* SSP (SPI) Control Register */
#define SSPSTAT (*((volatile u8 *)0x94)) /* SSP Status Register */
#define SSPBUF (*((volatile u8 *)0x13))  /* SSP Buffer Register */
#define SSPADD (*((volatile u8 *)0x93))  /* SSP Address Register (Slave mode) */

/* SSPCON Bit Definitions */
#define SSPM0 0 /* SSP Mode Select Bits */
#define SSPM1 1
#define SSPM2 2
#define SSPM3 3
#define CKE 4 /* SPI Clock Edge Select */
#define SMP 7 /* SPI Data Sample Bit */

/* SSPSTAT Bit Definitions */
#define BF 0         /* Buffer Full Status Bit */
#define UA 1         /* Update Address Bit */
#define R_W 2        /* Read/Write Status Bit */
#define S 3          /* Start Condition Status Bit */
#define P 4          /* Stop Condition Status Bit */
#define D_A 5        /* Data/Address Bit */
#define CKP 6        /* Clock Polarity Select Bit */
#define SMP_STATUS 7 /* SPI Data Sample Bit */

/* Port C Configuration (SPI pins) */
#define PORTC (*((volatile u8 *)0x07))
#define TRISC (*((volatile u8 *)0x87))

/* Interrupt Registers */
#define PIR1 (*((volatile u8 *)0x0C))
#define PIE1 (*((volatile u8 *)0x8C))
#define SSPIF 3 /* SPI Interrupt Flag */
#define SSIE 3  /* SPI Interrupt Enable */

#endif
