#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

#define SPI_MASTER_FOSC_4     0x00
#define SPI_MASTER_FOSC_16    0x01
#define SPI_MASTER_FOSC_64    0x02
#define SPI_MASTER_TMR2_2     0x03

void SPI_MasterInit(u8 ClockSelect);
void SPI_SlaveInit(void);
u8   SPI_Transceive(u8 Data);

#endif
