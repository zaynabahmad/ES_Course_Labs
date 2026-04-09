#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"


#define MSSP_DATA_REG       (*(volatile u8*)0x13)
#define MSSP_CTRL1_REG      (*(volatile u8*)0x14)
#define PIR1_REG            (*(volatile u8*)0x0C)

#define MSSP_STAT_REG       (*(volatile u8*)0x94)
#define TRISC_REG           (*(volatile u8*)0x87)

#define CTRL1_SSPEN         5
#define CTRL1_CKP           4

#define STAT_SMP            7
#define STAT_CKE            6
#define STAT_BF             0


#define PIR1_SSPIF          3


#define SPI_SPEED_FOSC_4    0x00
#define SPI_SPEED_FOSC_16   0x01
#define SPI_SPEED_FOSC_64   0x02
#define SPI_SPEED_TMR2      0x03
#define SPI_SLAVE_SS_EN     0x04
#define SPI_SLAVE_SS_DIS    0x05

#define SPI_MODE_MASK       0x0F

#endif /* SPI_PRIVATE_H */