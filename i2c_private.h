#ifndef I2C_PRIVATE_H
#define I2C_PRIVATE_H

#include "../../SERVICES/types.h"

#define SSPCON_REG      (*((volatile u8*)0x14))
#define SSPCON2_REG     (*((volatile u8*)0x91))
#define SSPSTAT_REG     (*((volatile u8*)0x94))
#define SSPADD_REG      (*((volatile u8*)0x93))
#define SSPBUF_REG      (*((volatile u8*)0x13))
#define PIR1_REG        (*((volatile u8*)0x0C))
#define TRISC_REG       (*((volatile u8*)0x87))

/* Bits */
#define SSPEN   5
#define SSPIF   3
#define SEN     0
#define PEN     2
#define RCEN    3
#define ACKEN   4
#define ACKDT   5

#endif