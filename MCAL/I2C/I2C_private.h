#ifndef I2C_PRIVATE_H
#define I2C_PRIVATE_H

#define SSPCON   (*((volatile u8*)0x14))
#define SSPCON2  (*((volatile u8*)0x91))
#define SSPSTAT  (*((volatile u8*)0x94))
#define SSPBUF   (*((volatile u8*)0x13))
#define SSPADD   (*((volatile u8*)0x93))

#define PIR1     (*((volatile u8*)0x0C))

#define TRISC    (*((volatile u8*)0x87))

#endif