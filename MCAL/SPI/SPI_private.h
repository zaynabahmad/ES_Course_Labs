#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

/* Register Addresses */
#define SSPBUF   (*((volatile u8*)0x13))
#define SSPCON   (*((volatile u8*)0x14))
#define SSPSTAT  (*((volatile u8*)0x94))

/* SSPCON bits */
#define SSPEN_BIT   5   /* Synchronous serial port enable */
#define CKP_BIT     4   /* Clock polarity */
#define SSPM3_BIT   3
#define SSPM2_BIT   2
#define SSPM1_BIT   1
#define SSPM0_BIT   0

/* SSPSTAT bits */
#define SMP_BIT     7   /* Sample bit: 0=middle, 1=end of data */
#define CKE_BIT     6   /* Clock edge: 0=idle→active, 1=active→idle */
#define BF_BIT      0   /* Buffer full */

#endif
