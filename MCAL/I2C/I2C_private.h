#ifndef I2C_PRIVATE_H
#define I2C_PRIVATE_H

#include "../../SERVICES/BIT_MATH.h"
#include "../../SERVICES/STD_TYPES.h"


#define SSPCON_REG (*((volatile unsigned char*)0x14))
#define SSPSTAT_REG (*((volatile unsigned char*)0x94))
#define SSPBUF_REG (*((volatile unsigned char*)0x13))
#define SSPADD_REG  (*((volatile u8*)0x93))
#define PIR1_REG    (*((volatile u8*)0x0C))

// Bits
#define SSPIF_BIT   3

#endif