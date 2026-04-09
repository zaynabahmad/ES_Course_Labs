#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H
#include "../../SERVICES/STD_TYPES.h"
void SPI_Init(void);
u8 SPI_Transmit(u8 _data);
#endif