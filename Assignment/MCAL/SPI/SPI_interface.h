#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

#include "STD_TYPES.h"

void SPI_InitMaster(void);
void SPI_InitSlave(void);

u8 SPI_u8SendRcve(u8 data);  // full duplex

#endif