#ifndef I2C_PRIVATE_H
#define I2C_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

#define TRISC       (*((volatile u8*)0x87))

#define SSPBUF      (*((volatile u8*)0x13))
#define SSPCON      (*((volatile u8*)0x14))
#define SSPCON2     (*((volatile u8*)0x91))
#define SSPSTAT     (*((volatile u8*)0x94))
#define SSPADD      (*((volatile u8*)0x93))
#define PIR1        (*((volatile u8*)0x0C))

#define SSPIF_BIT   3
#define BF_BIT      0
#define SEN_BIT     0
#define RSEN_BIT    1
#define PEN_BIT     2
#define RCEN_BIT    3
#define ACKEN_BIT   4
#define ACKDT_BIT   5
#define ACKSTAT_BIT 6

#endif
