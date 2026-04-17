#ifndef I2C_PRIVATE_H
#define I2C_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

#define SSPCON   (*((volatile u8*)0x14))
#define SSPCON2  (*((volatile u8*)0x91))
#define SSPSTAT  (*((volatile u8*)0x94))
#define SSPBUF   (*((volatile u8*)0x13))
#define SSPADD   (*((volatile u8*)0x93))
#define TRISC    (*((volatile u8*)0x87))
#define PIR1     (*((volatile u8*)0x0C))

/* SSPCON bits */
#define SSPEN   5
#define CKP     4

/* SSPCON2 bits */
#define SEN     0
#define RSEN    1
#define PEN     2
#define RCEN    3
#define ACKEN   4
#define ACKDT   5
#define ACKSTAT 6

/* SSPSTAT bits */
#define BF      0
#define RW      2
#define S_BIT   3
#define P_BIT   4

/* PIR1 bits */
#define SSPIF   3

#endif
