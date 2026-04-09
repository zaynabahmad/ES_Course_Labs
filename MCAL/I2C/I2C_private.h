#ifndef I2C_PRIVATE_H
#define I2C_PRIVATE_H

#define SSPCON   (*((volatile u8*)0x14))
#define SSPCON2  (*((volatile u8*)0x91))
#define SSPSTAT  (*((volatile u8*)0x94))
#define SSPADD   (*((volatile u8*)0x93))
#define SSPBUF   (*((volatile u8*)0x13))
#define PIR1     (*((volatile u8*)0x0C))

#define TRISC    (*((volatile u8*)0x87))

/* Bits */
#define SSPEN   5
#define SSPIF   3

#define SEN     0
#define PEN     2
#define RCEN    3
#define ACKEN   4
#define ACKDT   5

#endif