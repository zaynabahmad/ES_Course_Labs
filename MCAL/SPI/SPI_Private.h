#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

#define INTCON (*((volatile u8 *)0x0B))
#define ADCON1 (*((volatile u8 *)0x9F))

#define PIR1 (*((volatile u8 *)0x0C))
#define PIE1 (*((volatile u8 *)0x8C))

#define SSPBUF (*((volatile u8 *)0x13))
#define SSPCON (*((volatile u8 *)0x14))
#define SSPSTAT (*((volatile u8 *)0x94))
#endif
