#ifndef I2C_PRIVATE_H
#define I2C_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

#define SSPCON    (*((volatile u8*)0x14))
#define SSPCON2   (*((volatile u8*)0x91))
#define SSPSTAT   (*((volatile u8*)0x94))
#define SSPBUF    (*((volatile u8*)0x13))
#define SSPADD    (*((volatile u8*)0x93))
#define TRISB     (*((volatile u8*)0x86))
#define PORTB     (*((volatile u8*)0x06))
#define PIE1      (*((volatile u8*)0x8C))
#define PIR1      (*((volatile u8*)0x0C))
#define INTCON    (*((volatile u8*)0x0B))

#define SSPM0     0
#define SSPM1     1
#define SSPM2     2
#define SSPM3     3
#define CKP       4
#define SSPEN     5
#define SSPOV     6
#define WCOL      7

#define BF        0
#define UA        1
#define R_W       2
#define S         3
#define P         4
#define D_A       5
#define CKE       6
#define SMP       7

#define SEN       0
#define RSEN      1
#define PEN       2
#define RCEN      3
#define ACKEN     4
#define ACKDT     5
#define ACKSTAT   6
#define GCEN      7

#define SSPIE     3
#define SSPIF     3

#define I2C_MASTER_MODE         0x08
#define I2C_SLAVE_MODE_7BIT     0x06
#define I2C_SLAVE_MODE_10BIT    0x07

#define I2C_START_BIT           0x01
#define I2C_STOP_BIT            0x02
#define I2C_OPERATION_IDLE      0x04

#endif
