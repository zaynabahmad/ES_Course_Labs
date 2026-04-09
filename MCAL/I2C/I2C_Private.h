#ifndef I2C_PRIVATE_H
#define I2C_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"


#define MSSP_BUF_REG        (*(volatile u8*)0x13)
#define MSSP_CON1_REG       (*(volatile u8*)0x14)
#define PIR1_REG            (*(volatile u8*)0x0C)
#define MSSP_CON2_REG       (*(volatile u8*)0x91)
#define MSSP_ADD_REG        (*(volatile u8*)0x93)
#define MSSP_STAT_REG       (*(volatile u8*)0x94)


#define CON1_SSPEN          5
#define CON1_CKP            4


#define I2C_MASTER_MODE_MASK  0x08 


#define CON2_GCEN           7
#define CON2_ACKSTAT        6
#define CON2_ACKDT          5
#define CON2_ACKEN          4
#define CON2_RCEN           3
#define CON2_PEN            2
#define CON2_RSEN           1
#define CON2_SEN            0


#define STAT_BF             0
#define PIR1_SSPIF          3


#define TRISC_REG           (*(volatile u8*)0x87)


#define SSPIF_BIT           3
#define SEN_BIT             0
#define RSEN_BIT            1
#define PEN_BIT             2
#define RCEN_BIT            3
#define ACKEN_BIT           4
#define ACKDT_BIT           5
#define ACKSTAT_BIT         6
#endif /* I2C_PRIVATE_H */