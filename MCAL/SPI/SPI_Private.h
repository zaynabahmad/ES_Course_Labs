#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

#define SSPSTAT (*((volatile u8*)0x94))
#define SSPCON  (*((volatile u8*)0x14))
#define SSPBUF  (*((volatile u8*)0x13))

#define BF      0
#define SMP     7
#define CKE     6

#define SSPM0   0
#define SSPM1   1
#define SSPM2   2
#define SSPM3   3
#define CKP     4
#define SSPEN   5

#endif
