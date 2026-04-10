#ifndef I2C_PRIVATE_H
#define I2C_PRIVATE_H

#define INTCON (*((volatile u8 *)0x0B))

#define PIR1 (*((volatile u8 *)0x0C))
#define PIE1 (*((volatile u8 *)0x8C))

#define SSPBUF (*((volatile u8 *)0x13))
#define SSPCON (*((volatile u8 *)0x14))
#define SSPCON2 (*((volatile u8 *)0x91))
#define SSPADD (*((volatile u8 *)0x93))
#define SSPSTAT (*((volatile u8 *)0x94))
#endif
