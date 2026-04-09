#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

#define SSPCON_REG    (*((volatile unsigned char*)0x14))
#define SSPSTAT_REG   (*((volatile unsigned char*)0x94))
#define SSPBUF_REG    (*((volatile unsigned char*)0x13))
#define TRISC_REG     (*((volatile unsigned char*)0x87))
#define TRISA_REG     (*((volatile unsigned char*)0x85))

#endif