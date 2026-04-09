#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

/* MSSP Registers (SPI mode) */
#define SSPCON      (*((volatile u8*)0x14))
#define SSPSTAT     (*((volatile u8*)0x94))
#define SSPBUF      (*((volatile u8*)0x13))

/* SSPCON Bits */
#define SSPEN_BIT   5
#define CKP_BIT     4
#define SSPM3_BIT   3
#define SSPM2_BIT   2
#define SSPM1_BIT   1
#define SSPM0_BIT   0
#define WCOL_BIT    7
#define SSPOV_BIT   6

/* SSPSTAT Bits */
#define SMP_BIT     7  
#define CKE_BIT     6  
#define BF_BIT      0  

/* TRISC for SPI pins */
#define TRISC       (*((volatile u8*)0x87))
#define SCK_PIN     3   
#define SDI_PIN     4   
#define SDO_PIN     5   

/* PIR1 for SSPIF */
#define PIR1        (*((volatile u8*)0x0C))
#define SSPIF_BIT   3

#endif
