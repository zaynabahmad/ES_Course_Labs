#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

/* --- Register Definitions --- */
#define SSPBUF  (*((volatile u8 *)0x13))
#define SSPCON  (*((volatile u8 *)0x14))
#define SSPSTAT (*((volatile u8 *)0x94))
#define PIR1    (*((volatile u8 *)0x0C)) /* Needed for interrupt flag */
#define PIE1    (*((volatile u8 *)0x8C)) /* Needed for interrupt enable */

/* --- SSPSTAT Bits --- */
#define BF_BIT  0  
#define CKE_BIT 6  
#define SMP_BIT 7  

/* --- SSPCON Bits --- */
#define SSPM0_BIT 0
#define SSPM1_BIT 1
#define SSPM2_BIT 2
#define SSPM3_BIT 3
#define CKP_BIT   4  
#define SSPEN_BIT 5  

/* --- PIR1 Bits --- */
#define SSPIF_BIT 3 /* MSSP Interrupt Flag */

/* --- PIE1 Bits --- */
#define SSPIE_BIT 3 /* MSSP Interrupt Enable */

#endif