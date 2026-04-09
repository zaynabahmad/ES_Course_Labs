#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

/* PIC16F877A SPI/MSSP Registers */
#define SSPCON      (*(volatile u8*)0x14)
#define SSPSTAT     (*(volatile u8*)0x94)
#define SSPADD      (*(volatile u8*)0x93)
#define SSPBUF      (*(volatile u8*)0x13)

/* SSPCON Bits */
#define SSPM0       0
#define SSPM1       1
#define SSPM2       2
#define SSPM3       3
#define CKP         4
#define SSPEN       5

/* SSPSTAT Bits */
#define BF          0
#define CKE         6
#define SMP         7

/* SPI Master Modes */
#define SPI_MASTER_FOSC_4   0x00
#define SPI_MASTER_FOSC_16  0x01
#define SPI_MASTER_FOSC_64  0x02

#endif
