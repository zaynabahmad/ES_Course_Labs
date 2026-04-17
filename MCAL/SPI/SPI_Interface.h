#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"
#include "SPI_Private.h"
#include "SPI_Config.h"

void SPI_Init(void);
u8   SPI_Transceive(u8 Data);
void SPI_SelectSlave(void);
void SPI_DeselectSlave(void);

#endif
