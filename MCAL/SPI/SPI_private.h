#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

/* PIC16F877A MSSP Registers */
#define SSPSTAT   (*((volatile u8*)0x94))
#define SSPCON    (*((volatile u8*)0x14))
#define SSPBUF    (*((volatile u8*)0x13))
#define PIR1      (*((volatile u8*)0x0C))
#define TRISC     (*((volatile u8*)0x87))

/* SSPSTAT Bits */
#define BF_BIT        0
#define CKE_BIT       6
#define SMP_BIT       7

/* SSPCON Bits */
#define SSPM0_BIT     0
#define SSPM1_BIT     1
#define SSPM2_BIT     2
#define SSPM3_BIT     3
#define CKP_BIT       4
#define SSPEN_BIT     5
#define SSPOV_BIT     6
#define WCOL_BIT      7

/* PIR1 Bits */
#define SSPIF_BIT     3

#endif