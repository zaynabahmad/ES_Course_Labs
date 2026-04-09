#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

/* Registers (PIC16F877A) */

#define SSPCON   (*((volatile u8*)0x14))
#define SSPSTAT  (*((volatile u8*)0x94))
#define SSPBUF   (*((volatile u8*)0x13))

/* Bits */
#define SSPEN    5
#define BF       0

#endif