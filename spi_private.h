#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

#include "../../SERVICES/types.h"

#define SSPCON_REG      (*((volatile u8*)0x14))
#define SSPSTAT_REG     (*((volatile u8*)0x94))
#define SSPBUF_REG      (*((volatile u8*)0x13))
#define PIR1_REG        (*((volatile u8*)0x0C))
#define TRISC_REG       (*((volatile u8*)0x87))

/* Bits */
#define SSPEN   5
#define BF      0
#define SSPIF   3

#endif