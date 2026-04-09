#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"
#include "SPI_Private.h"
#include "SPI_Config.h"

#define SPI_MASTER_FOSC_4   0x00
#define SPI_MASTER_FOSC_16  0x01
#define SPI_MASTER_FOSC_64  0x02
#define SPI_MASTER_TMR2     0x03
#define SPI_SLAVE_SS        0x04
#define SPI_SLAVE_NO_SS     0x05

void SPI_Init(u8 Mode);
u8 SPI_Transceive(u8 Data);
void SPI_Write(u8 Data);
u8 SPI_Read(void);

#endif
