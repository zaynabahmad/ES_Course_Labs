#ifndef I2C_PRIVATE_H
#define I2C_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

/* Registers (PIC16F877A) */

#define SSPCON   (*((volatile u8*)0x14))
#define SSPSTAT  (*((volatile u8*)0x94))
#define SSPBUF   (*((volatile u8*)0x13))
#define SSPADD   (*((volatile u8*)0x93))

/* Bits */
#define SSPEN    5
#define SEN      0
#define PEN      2
#define BF       0

#endif