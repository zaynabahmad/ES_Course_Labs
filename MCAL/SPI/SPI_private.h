#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

/* MSSP Registers for SPI */
#define SSPSTAT         *((volatile u8*)0x94)
#define SSPCON          *((volatile u8*)0x14)
#define SSPBUF          *((volatile u8*)0x13)

/* Port & Direction for SPI Pins */
#define TRISC           *((volatile u8*)0x87)
#define PORTC           *((volatile u8*)0x07)
#define SCL_SCK_PIN     3
#define SDI_PIN         4
#define SDO_PIN         5

/* PIR1 for Interrupt Flag */
#define PIR1            *((volatile u8*)0x0C)
#define SSPIF           3

/* SSPSTAT Bit Definitions */
#define SSPSTAT_SMP     7   /* Sample bit (0=Middle, 1=End) */
#define SSPSTAT_CKE     6   /* Clock Edge Select */
#define SSPSTAT_BF      0   /* Buffer Full Status bit */

/* SSPCON Bit Definitions */
#define SSPCON_SSPEN    5   /* SSP Enable */
#define SSPCON_CKP      4   /* Clock Polarity Select */

#endif