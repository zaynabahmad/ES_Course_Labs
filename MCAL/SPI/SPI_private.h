#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

#define SSPCON_REG   (*((volatile u8*)0x14))
#define SSPSTAT_REG  (*((volatile u8*)0x94))
#define SSPBUF_REG   (*((volatile u8*)0x13))
#define TRISC_REG    (*((volatile u8*)0x87))

#define BF_BIT       0
#define SSPEN_BIT    5
#define CKP_BIT      4
#define CKE_BIT      6
#define SMP_BIT      7

#endif