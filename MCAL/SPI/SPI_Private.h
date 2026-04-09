#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

/* Register Definitions for PIC16F877A SPI (SSP Module) */
#define SSPCON          (*((volatile u8*)0x14))
#define SSPSTAT         (*((volatile u8*)0x94))
#define SSPBUF          (*((volatile u8*)0x13))

/* SSPCON Bits */
#define SSPM0           0
#define SSPM1           1
#define SSPM2           2
#define SSPM3           3
#define CKP             4
#define SSPEN           5
#define SSPOV           6
#define WCOL            7

/* SSPSTAT Bits */
#define BF              0
#define UA              1
#define R_W             2
#define S               3
#define P               4
#define D_A             5
#define CKE             6
#define SMP             7

#endif
