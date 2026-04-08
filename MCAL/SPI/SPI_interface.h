#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

void SPI_Init(void);
unsigned char SPI_Transfer (unsigned char u8Data);

#endif