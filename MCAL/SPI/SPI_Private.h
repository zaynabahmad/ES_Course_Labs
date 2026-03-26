#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

#define SSPCON  (*((volatile u8*)0x14))
#define SSPSTAT (*((volatile u8*)0x94))
#define SSPBUF  (*((volatile u8*)0x13))

#define TRISC   (*((volatile u8*)0x87))
#define TRISA   (*((volatile u8*)0x85))
#define PORTC   (*((volatile u8*)0x07))
#define PORTA   (*((volatile u8*)0x05))

/* SSPCON Bits */
#define SSPM0   0
#define SSPM1   1
#define SSPM2   2
#define SSPM3   3
#define CKP     4
#define SSPEN   5
#define SSPOV   6
#define WCOL    7

/* SSPSTAT Bits */
#define BF      0
#define CKE     6
#define SMP     7

#endif
