#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

#define SSPBUF (*(volatile unsigned char*)0x13)
#define SSPSTAT (*(volatile unsigned char*)0x94)
#define SSPCON  (*(volatile unsigned char*)0x14)

#endif