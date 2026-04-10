#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

/* SPI Peripheral Registers */
#define SSPSTAT     (*((volatile uint8*)0x94))
#define SSPCON      (*((volatile uint8*)0x14))
#define SSPBUF      (*((volatile uint8*)0x13))

/* Significant Bits */
#define BF_BIT      0   /* Buffer Full Status bit */
#define CKP_BIT     4   /* Clock Polarity Select bit */
#define SSPEN_BIT   5   /* Synchronous Serial Port Enable bit */
#define SMP_BIT     7   /* Sample bit */
#define CKE_BIT     6   /* Clock Edge Select bit */

#endif