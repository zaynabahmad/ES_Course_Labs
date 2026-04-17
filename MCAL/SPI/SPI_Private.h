#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

#define SSPCON   (*((volatile u8*)0x14))
#define SSPSTAT  (*((volatile u8*)0x94))
#define SSPBUF   (*((volatile u8*)0x13))
#define TRISC    (*((volatile u8*)0x87))
#define TRISA    (*((volatile u8*)0x85))
#define PORTA    (*((volatile u8*)0x05))

/* SSPCON bits */
#define SSPEN   5
#define CKP     4
#define WCOL    7
#define SSPOV   6

/* SSPSTAT bits */
#define SMP     7
#define CKE     6
#define BF      0

/* SPI Mode pins (RC3=SCK, RC4=SDI, RC5=SDO, RA5=SS) */
#define SPI_SCK_PIN  3
#define SPI_SDI_PIN  4
#define SPI_SDO_PIN  5
#define SPI_SS_PIN   5   /* RA5 */

#endif
