#ifndef I2C_PRIVATE_H
#define I2C_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

/* PIC16F877A I2C/MSSP Registers */
#define SSPCON      (*(volatile u8*)0x14)
#define SSPSTAT     (*(volatile u8*)0x94)
#define SSPADD      (*(volatile u8*)0x93)
#define SSPBUF      (*(volatile u8*)0x13)

/* SSPCON Bits */
#define SSPM0       0
#define SSPM1       1
#define SSPM2       2
#define SSPM3       3
#define CKP         4
#define SSPEN       5

/* SSPSTAT Bits */
#define BF          0
#define UA          1
#define STOP        4
#define START       3
#define RW          2
#define DA          5

/* I2C Mode (Master Mode) */
#define I2C_MASTER_MODE  0x08

#endif
