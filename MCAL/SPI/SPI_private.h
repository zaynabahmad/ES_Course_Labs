#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

#define SSPCON  (*((volatile u8*)0x14))
#define SSPSTAT (*((volatile u8*)0x94))
#define SSPBUF  (*((volatile u8*)0x13))
#define TRISC   (*((volatile u8*)0x87))
#define TRISA   (*((volatile u8*)0x85))
#define ADCON1  (*((volatile u8*)0x9F))

#endif