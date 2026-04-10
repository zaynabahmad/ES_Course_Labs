#ifndef I2C_PRIVATE_H
#define I2C_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

/* I2C Peripheral Registers */
#define SSPCON      (*((volatile uint8*)0x14))
#define SSPCON2     (*((volatile uint8*)0x91))
#define SSPSTAT     (*((volatile uint8*)0x94))
#define SSPBUF      (*((volatile uint8*)0x13))
#define SSPADD      (*((volatile uint8*)0x93))

/* Significant Bits */
#define SEN_BIT     0   /* Start Enable bit */
#define RSEN_BIT    1   /* Repeated Start bit */
#define PEN_BIT     2   /* Stop Enable bit */
#define RCEN_BIT    3   /* Receive Enable bit */
#define ACKEN_BIT   4   /* Acknowledge Sequence Enable */
#define ACKDT_BIT   5   /* Acknowledge Data bit */
#define ACKSTAT_BIT 6   /* Acknowledge Status bit */

#endif