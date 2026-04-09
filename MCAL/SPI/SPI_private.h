#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

// MSSP Registers for SPI
#define SSPSTAT (*((volatile u8*)0x94))
#define SSPCON  (*((volatile u8*)0x14))
#define SSPBUF  (*((volatile u8*)0x13))
#define PIR1    (*((volatile u8*)0x0C))

// SSPSTAT Bits
#define SMP 7
#define CKE 6
#define BF  0   // Buffer Full Status bit

// SSPCON Bits
#define SSPEN 5 // SPI Enable bit
#define CKP   4 // Clock Polarity bit

// PIR1 Bits
#define SSPIF 3 // SPI Interrupt Flag

#endif