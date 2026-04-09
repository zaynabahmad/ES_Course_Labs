#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

#define TRISA       (*((volatile u8*)0x85))
#define TRISC       (*((volatile u8*)0x87))

#define SSPBUF      (*((volatile u8*)0x13))
#define SSPCON      (*((volatile u8*)0x14))
#define SSPSTAT     (*((volatile u8*)0x94))
#define PIR1        (*((volatile u8*)0x0C))

#define SSPEN_BIT   5
#define BF_BIT      0

#endif
