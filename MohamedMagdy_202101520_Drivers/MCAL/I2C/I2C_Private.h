#ifndef I2C_PRIVATE_H
#define I2C_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

#ifndef SSPBUF
#define SSPBUF      (*(volatile u8*)0x13)
#endif

#ifndef SSPCON
#define SSPCON      (*(volatile u8*)0x14)
#endif

#define SSPCON2     (*(volatile u8*)0x91)

#ifndef SSPSTAT
#define SSPSTAT     (*(volatile u8*)0x94)
#endif

#define SSPADD      (*(volatile u8*)0x93)

#ifndef PIR1
#define PIR1        (*(volatile u8*)0x0C)
#endif

#ifndef SSPEN_BIT
#define SSPEN_BIT   5
#endif
#define CKP_I2C_BIT 4

#define I2C_MASTER_MODE     0x08

#define GCEN_BIT    7
#define ACKSTAT_BIT 6
#define ACKDT_BIT   5
#define ACKEN_BIT   4
#define RCEN_BIT    3
#define PEN_BIT     2
#define RSEN_BIT    1
#define SEN_BIT     0

#ifndef BF_BIT
#define BF_BIT      0
#endif

#ifndef SSPIF_BIT
#define SSPIF_BIT   3
#endif

#endif
