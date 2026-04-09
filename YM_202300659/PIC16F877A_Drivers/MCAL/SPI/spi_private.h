/*
 * spi_private.h
 * MCAL - SPI (MSSP) Register Definitions for PIC16F877A
 */

#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

/* =====================================================
 * MSSP Registers (SPI Mode)
 * ===================================================== */

/* SSPBUF - SSP Receive/Transmit Buffer (Bank 0) */
#define SSPBUF_REG     (*((volatile unsigned char*)0x13))

/* SSPCON - SSP Control Register (Bank 0) */
#define SSPCON_REG     (*((volatile unsigned char*)0x14))

/* SSPSTAT - SSP Status Register (Bank 1) */
#define SSPSTAT_REG    (*((volatile unsigned char*)0x94))

/* TRISC - Direction Register for SPI pins (Bank 1) */
#define TRISC_REG      (*((volatile unsigned char*)0x87))

/* =====================================================
 * SSPCON Bit Positions
 * ===================================================== */
#define SSPCON_WCOL     7   /* Write Collision Detect      */
#define SSPCON_SSPOV    6   /* Receive Overflow Indicator  */
#define SSPCON_SSPEN    5   /* SSP Enable                  */
#define SSPCON_CKP      4   /* Clock Polarity: 1=idle high */
#define SSPCON_SSPM3    3   /* SSP Mode bits               */
#define SSPCON_SSPM2    2
#define SSPCON_SSPM1    1
#define SSPCON_SSPM0    0

/*
 * SSPM bits for SPI Master modes:
 * 0000 = SPI Master, Fosc/4
 * 0001 = SPI Master, Fosc/16
 * 0010 = SPI Master, Fosc/64
 * 0011 = SPI Master, TMR2/2
 * 0100 = SPI Slave, SS enabled
 * 0101 = SPI Slave, SS disabled
 */
#define SPI_MASTER_FOSC4   0x00
#define SPI_MASTER_FOSC16  0x01
#define SPI_MASTER_FOSC64  0x02
#define SPI_SLAVE_SS_EN    0x04
#define SPI_SLAVE_SS_DIS   0x05

/* =====================================================
 * SSPSTAT Bit Positions
 * ===================================================== */
#define SSPSTAT_SMP    7   /* Sample bit: 1=end, 0=middle */
#define SSPSTAT_CKE    6   /* Clock Edge: 1=active->idle  */
#define SSPSTAT_BF     0   /* Buffer Full Status          */

/* PIR1 for SSPIF */
#define PIR1_REG       (*((volatile unsigned char*)0x0C))
#define PIR1_SSPIF     3   /* SSP Interrupt Flag          */

/*
 * SPI Pin Mapping on PIC16F877A:
 * SCK  = RC3 (pin 18)
 * SDI  = RC4 (pin 23) - MISO
 * SDO  = RC5 (pin 24) - MOSI
 * SS   = RA5 (pin 7)  - Slave Select (manual control)
 */
#define SPI_SCK_BIT    3
#define SPI_SDI_BIT    4
#define SPI_SDO_BIT    5

#define TRISA_REG      (*((volatile unsigned char*)0x85))
#define SPI_SS_PORT    (*((volatile unsigned char*)0x05))   /* PORTA */
#define SPI_SS_BIT     5

#endif /* SPI_PRIVATE_H */
