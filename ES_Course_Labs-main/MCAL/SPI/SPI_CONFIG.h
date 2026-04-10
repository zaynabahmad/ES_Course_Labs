#ifndef SPI_CONFIG_H
#define SPI_CONFIG_H
#define SSPEN  5   // SPI Enable
#define CKP    4   // Clock Polarity Select

// SPI Mode Select Bits
#define SSPM3  3
#define SSPM2  2
#define SSPM1  1
#define SSPM0  0


// ======================================================
//                SSPSTAT (SPI Status Register)
// ======================================================

#define SMP 7   // Input Data Sample Phase
#define CKE 6   // Clock Edge Select
#define BF  0   // Buffer Full Status

// ======================================================
//                INTERRUPT BITS (for SPI)
// ======================================================

// From PIR1
#define SSPIF 3   // SPI Interrupt Flag

// From PIE1
#define SSPIE 3   // SPI Interrupt Enable

// ADCON1 bits
#define PCFG3 3
#define PCFG2 2
#define PCFG1 1
#define PCFG0 0

#endif
