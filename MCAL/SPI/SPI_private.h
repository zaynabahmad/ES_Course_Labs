#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

/* MSSP Registers */
#define SSPBUF  *((volatile u8*)0x13)
#define SSPCON  *((volatile u8*)0x14)
#define SSPSTAT *((volatile u8*)0x94)

/* SSPCON Bits */
#define SSPEN   5
#define CKP     4
#define SSPM0   0
#define SSPM1   1
#define SSPM2   2
#define SSPM3   3
#define WCOL    7
#define SSPOV   6

/* SSPSTAT Bits */
#define SMP     7
#define CKE     6
#define BF      0

/* TRISC / PORTC (example for PIC16F877A) */
#define TRISC   *((volatile u8*)0x87)
#define PORTC   *((volatile u8*)0x07)

#define RC2 2
#define RC3 3
#define RC4 4
#define RC5 5

#endif