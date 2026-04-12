#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

/* ================= Register Addresses ================= */

#define SSPCON       (*((volatile u8*)0x14))
#define SSPCON2      (*((volatile u8*)0x91))
#define SSPSTAT      (*((volatile u8*)0x94))
#define SSPBUF       (*((volatile u8*)0x13))
#define SSPADD       (*((volatile u8*)0x93))
#define PIR1         (*((volatile u8*)0x0C))
#define TRISC        (*((volatile u8*)0x87))

/* ================= SSPCON Bits ================= */

#define SSPM0        0      /* Synchronous Serial Port Mode bit 0 */
#define SSPM1        1
#define SSPM2        2
#define SSPM3        3
#define CKP          4      /* Clock Polarity */
#define SSPEN        5      /* SSP Enable */
#define SSPOV        6      /* Receive Overflow Indicator */
#define WCOL         7      /* Write Collision Detect */

/* ================= SSPSTAT Bits ================= */

#define BF           0      /* Buffer Full Status */
#define UA           1      /* Update Address */
#define R_W          2      /* Read/Write Info */
#define S            3      /* Start bit */
#define P            4      /* Stop bit */
#define D_A          5      /* Data/Address */
#define CKE          6      /* Clock Edge Select */
#define SMP          7      /* Sample bit */

/* ================= PIR1 Bits ================= */

#define SSPIF        3

#endif
