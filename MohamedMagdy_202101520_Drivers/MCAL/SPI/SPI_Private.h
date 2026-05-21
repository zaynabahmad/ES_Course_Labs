#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

#ifndef SSPBUF
#define SSPBUF      (*(volatile u8*)0x13)
#endif

#ifndef SSPCON
#define SSPCON      (*(volatile u8*)0x14)
#endif

#ifndef SSPSTAT
#define SSPSTAT     (*(volatile u8*)0x94)
#endif

#ifndef PIR1
#define PIR1        (*(volatile u8*)0x0C)
#endif

#define SSPEN_BIT   5
#define CKP_BIT     4

#define SPI_MASTER_FOSC4    0x00
#define SPI_MASTER_FOSC16   0x01
#define SPI_MASTER_FOSC64   0x02
#define SPI_SLAVE_SS_EN     0x04
#define SPI_SLAVE_SS_DIS    0x05

#define SSPM_MASK           0x0F

#define SMP_BIT     7
#define CKE_BIT     6
#define BF_BIT      0

#define SSPIF_BIT   3

#endif
