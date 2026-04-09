#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

#define SSPSTAT  (*((volatile u8*)0x94))
#define SSPCON   (*((volatile u8*)0x14))
#define SSPBUF   (*((volatile u8*)0x13))

#define TRISC    (*((volatile u8*)0x87))

#endif