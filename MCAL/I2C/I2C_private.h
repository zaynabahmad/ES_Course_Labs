#ifndef I2C_PRIVATE_H
#define I2C_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

#define SSPCON_REG   (*((volatile u8*)0x14))
#define SSPCON2_REG  (*((volatile u8*)0x91))
#define SSPSTAT_REG  (*((volatile u8*)0x94))
#define SSPBUF_REG   (*((volatile u8*)0x13))
#define SSPADD_REG   (*((volatile u8*)0x92))
#define TRISC_REG    (*((volatile u8*)0x87))

#define SSPEN_BIT    5
#define CKP_BIT      4
#define SEN_BIT      0
#define RSEN_BIT     1
#define PEN_BIT      2
#define RCEN_BIT     3
#define ACKEN_BIT    4
#define ACKDT_BIT    5
#define ACKSTAT_BIT  6
#define BF_BIT       0
#define SDA_BIT      4
#define SCL_BIT      3

#endif