#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

#define SSPCON    (*((volatile u8*)0x14))
#define SSPCON2   (*((volatile u8*)0x91))
#define SSPSTAT   (*((volatile u8*)0x94))
#define SSPBUF    (*((volatile u8*)0x13))
#define SSPSHR    (*((volatile u8*)0x25))
#define SSPADD    (*((volatile u8*)0x93))
#define TRISC     (*((volatile u8*)0x87))
#define TRISB     (*((volatile u8*)0x86))
#define PORTC     (*((volatile u8*)0x07))
#define PORTB     (*((volatile u8*)0x06))
#define PIE1      (*((volatile u8*)0x8C))
#define PIR1      (*((volatile u8*)0x0C))
#define INTCON    (*((volatile u8*)0x0B))

#define SSPM0     0
#define SSPM1     1
#define SSPM2     2
#define SSPM3     3
#define CKP       4
#define SSPEN     5
#define SSPOV     6
#define WCOL      7

#define BF        0
#define UA        1
#define R_W       2
#define S         3
#define P         4
#define D_A       5
#define CKE       6
#define SMP       7

#define SSPIE     3
#define SSPIF     3

#define SPI_MASTER_MODE_1       0x20
#define SPI_MASTER_MODE_2       0x21
#define SPI_MASTER_MODE_3       0x22
#define SPI_SLAVE_MODE_4        0x04
#define SPI_SLAVE_MODE_5        0x05

#endif
