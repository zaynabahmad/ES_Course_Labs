#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

void SPI_InitMaster(void);
void SPI_InitSlave(void);
u8 SPI_Transfer(u8 Data);

#endif
