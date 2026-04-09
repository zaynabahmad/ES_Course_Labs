#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

#define SSPSTAT   (*(volatile uint8*)0xA3)
#define SSPCON    (*(volatile uint8*)0xA0)
#define SSPBUF    (*(volatile uint8*)0xA1)

#endif