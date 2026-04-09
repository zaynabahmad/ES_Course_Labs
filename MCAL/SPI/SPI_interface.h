#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

void SPI_Master_Init(void);
void SPI_Slave_Init(void);
u8 SPI_Transfer(u8 data);

#endif