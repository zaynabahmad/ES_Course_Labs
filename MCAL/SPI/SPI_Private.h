#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

#define SSPBUF  (*((volatile u8*)0x13))
#define SSPCON  (*((volatile u8*)0x14))
#define SSPSTAT (*((volatile u8*)0x94))
#define PIR1_S  (*((volatile u8*)0x0C))

#define SSPEN_BIT 5
#define CKP_BIT   4
#define BF_BIT    0
#define SMP_BIT   7
#define CKE_BIT   6
#define SSPIF_BIT 3

#endif
