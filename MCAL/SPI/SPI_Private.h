#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

/* ================= Register Addresses ================= */

#define SSPBUF   (*(volatile unsigned char*)0x13)
#define SSPCON   (*(volatile unsigned char*)0x14)
#define SSPSTAT  (*(volatile unsigned char*)0x94)
#define TRISC    (*(volatile unsigned char*)0x87)
#define TRISA    (*(volatile unsigned char*)0x85)
#define ADCON1   (*(volatile unsigned char*)0x9F)
#define PIR1     (*(volatile unsigned char*)0x0C)
#define PIE1     (*(volatile unsigned char*)0x8C)
#define INTCON   (*(volatile unsigned char*)0x0B)

/* ================= SSPCON Bits ================= */

#define SSPM0    0
#define SSPM1    1
#define SSPM2    2
#define SSPM3    3
#define CKP_BIT  4    /* Clock Polarity */
#define SSPEN    5    /* Synchronous Serial Port Enable */
#define SSPOV    6    /* Receive Overflow Indicator */
#define WCOL     7    /* Write Collision Detect */

/* ================= SSPSTAT Bits ================= */

#define BF       0    /* Buffer Full Status */
#define CKE_BIT  6    /* SPI Clock Edge Select */
#define SMP_BIT  7    /* SPI Data Input Sample Phase */

/* ================= PIR1 Bits ================= */

#define SSPIF    3    /* MSSP Interrupt Flag */

/* ================= PIE1 Bits ================= */

#define SSPIE    3    /* MSSP Interrupt Enable */

/* ================= INTCON Bits ================= */

#define PEIE     6    /* Peripheral Interrupt Enable */
#define GIE      7    /* Global Interrupt Enable */

/* ================= TRISC Bit Positions ================= */

#define RC3      3    /* SCK — Output (Master) / Input (Slave) */
#define RC4      4    /* SDI — Input  (auto-controlled by MSSP)  */
#define RC5      5    /* SDO — Output */

/* ================= TRISA Bit Positions ================= */

#define RA5      5    /* SS — Input (Slave Select) */

/* ================= SPI Mode Selector Codes (SSPM<3:0>) ================= */

#define SPI_MASTER_FOSC4    0x00  /* Master, SCK = FOSC/4  */
#define SPI_MASTER_FOSC16   0x01  /* Master, SCK = FOSC/16 */
#define SPI_MASTER_FOSC64   0x02  /* Master, SCK = FOSC/64 */
#define SPI_MASTER_TMR2     0x03  /* Master, SCK = TMR2/2  */
#define SPI_SLAVE_SS_EN     0x04  /* Slave,  SS pin enabled  */
#define SPI_SLAVE_SS_DIS    0x05  /* Slave,  SS pin disabled */

#endif
