#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

#define SSPBUF_REG (*((volatile u8*)0x13))
#define SSPSTAT_REG (*((volatile u8*)0x94))
#define SSPCON_REG (*((volatile u8*)0x14))

#define BF_BIT 0

#endif