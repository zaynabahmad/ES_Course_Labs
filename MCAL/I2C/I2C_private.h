#ifndef I2C_PRIVATE_H
#define I2C_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

/* SSP Control Register */
#define SSPCON   (*((volatile u8*)0x14))

/* SSP Control Register 2 */
#define SSPCON2  (*((volatile u8*)0x91))

/* SSP Status Register */
#define SSPSTAT  (*((volatile u8*)0x94))

/* SSP Buffer Register */
#define SSPBUF   (*((volatile u8*)0x13))

/* SSP Address Register */
#define SSPADD   (*((volatile u8*)0x93))

/* TRISC Register */
#define TRISC    (*((volatile u8*)0x87))

/* PIR1 Register - for interrupt flags */
#define PIR1     (*((volatile u8*)0x0C))

#endif