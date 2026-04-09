#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

#define SPCR (*(volatile unsigned char*)0x2D)
#define SPSR (*(volatile unsigned char*)0x2E)
#define SPDR (*(volatile unsigned char*)0x2F)

#define DDRB (*(volatile unsigned char*)0x37)

#endif