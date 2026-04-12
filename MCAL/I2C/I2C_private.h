#ifndef I2C_PRIVATE_H
#define I2C_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

/* Register Definitions for PIC16F877A - I2C (MSSP Module) */

/* MSSP Control Registers */
#define SSPCON (*((volatile u8 *)0x14))  /* SSP Control Register */
#define SSPSTAT (*((volatile u8 *)0x94)) /* SSP Status Register */
#define SSPADD (*((volatile u8 *)0x93))  /* SSP Address/Baud Rate */
#define SSPBUF (*((volatile u8 *)0x13))  /* SSP Buffer */

/* SSPCON Bit Definitions for I2C */
#define SSPM0 0 /* Mode Select Bits */
#define SSPM1 1
#define SSPM2 2
#define SSPM3 3
#define CKP 4   /* Clock Polarity Select */
#define SSPEN 5 /* SSP Enable Bit */
#define SSPOV 6 /* Receive Overflow Bit */
#define WCOL 7  /* Write Collision Bit */

/* SSPSTAT Bit Definitions */
#define BF 0  /* Buffer Full Status */
#define UA 1  /* Update Address */
#define R_W 2 /* Read/Write Status */
#define S 3   /* Start Condition */
#define P 4   /* Stop Condition */
#define D_A 5 /* Data/Address */
#define CKE 6 /* SMBus-related */
#define SMP 7 /* Slew Rate Control */

/* Port C Configuration */
#define PORTC (*((volatile u8 *)0x07))
#define TRISC (*((volatile u8 *)0x87))

/* Interrupt Registers */
#define PIR1 (*((volatile u8 *)0x0C))
#define PIE1 (*((volatile u8 *)0x8C))
#define SSPIF 3 /* SSP Interrupt Flag */
#define SSIE 3  /* SSP Interrupt Enable */

/* I2C Mode Selection */
#define I2C_MASTER_MODE 0x18 /* 1000 with CKP = 1 */
#define I2C_SLAVE_MODE 0x06  /* 0110 with 10-bit address disabled */

#endif
