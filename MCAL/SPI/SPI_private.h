#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

#define SSPCON   (*((volatile u8*)0x14))
#define SSPSTAT  (*((volatile u8*)0x94))
#define SSPBUF   (*((volatile u8*)0x13))
#define PIR1     (*((volatile u8*)0x0C))

#define TRISC    (*((volatile u8*)0x87))

/* Bits */
#define SSPEN   5
#define BF      0
#define SSPIF   3

#endif