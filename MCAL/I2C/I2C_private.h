#ifndef I2C_PRIVATE_H
#define I2C_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

/* PIC16F877A MSSP Registers */
#define SSPCON     (*((volatile u8*)0x14))
#define SSPCON2    (*((volatile u8*)0x91))
#define SSPSTAT    (*((volatile u8*)0x94))
#define SSPADD     (*((volatile u8*)0x93))
#define SSPBUF     (*((volatile u8*)0x13))
#define PIR1       (*((volatile u8*)0x0C))
#define TRISC      (*((volatile u8*)0x87))

/* SSPCON Bits */
#define SSPM0_BIT      0
#define SSPM1_BIT      1
#define SSPM2_BIT      2
#define SSPM3_BIT      3
#define SSPEN_BIT      5

/* SSPCON2 Bits */
#define SEN_BIT        0
#define RSEN_BIT       1
#define PEN_BIT        2
#define RCEN_BIT       3
#define ACKEN_BIT      4
#define ACKDT_BIT      5
#define ACKSTAT_BIT    6

/* SSPSTAT Bits */
#define BF_BIT         0
#define RW_BIT         2
#define SMP_BIT        7
#define CKE_BIT        6

/* PIR1 Bits */
#define SSPIF_BIT      3

#endif