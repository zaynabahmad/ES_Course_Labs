#ifndef I2C_PRIVATE_H
#define I2C_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

/* Register Addresses */
#define SSPBUF   (*((volatile u8*)0x13))
#define SSPCON   (*((volatile u8*)0x14))
#define SSPCON2  (*((volatile u8*)0x91))
#define SSPSTAT  (*((volatile u8*)0x94))
#define SSPADD   (*((volatile u8*)0x93))

/* SSPCON bits */
#define SSPEN_BIT   5
#define SSPM3_BIT   3
#define SSPM2_BIT   2
#define SSPM1_BIT   1
#define SSPM0_BIT   0

/* SSPCON2 bits */
#define GCEN_BIT    7
#define ACKSTAT_BIT 6
#define ACKDT_BIT   5
#define ACKEN_BIT   4
#define RCEN_BIT    3
#define PEN_BIT     2
#define RSEN_BIT    1
#define SEN_BIT     0

/* SSPSTAT bits */
#define SMP_BIT     7   /* Slew rate: 0=enabled (400 kHz), 1=disabled (100 kHz) */
#define BF_BIT      0   /* Buffer full */

#endif
