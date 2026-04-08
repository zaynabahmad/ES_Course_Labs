#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

/* SPI Status Register */
#define SSPSTAT  (*((volatile u8*)0x94))

/* SPI Control Register */
#define SSPCON   (*((volatile u8*)0x14))

/* SPI Buffer Register */
#define SSPBUF   (*((volatile u8*)0x13))

/* TRISC Register */
#define TRISC    (*((volatile u8*)0x87))

/* TRISB Register */
#define TRISB    (*((volatile u8*)0x86))

/* PORTB Register */
#define PORTB    (*((volatile u8*)0x06))

#endif