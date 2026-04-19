#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

#include "../../SERVICES/std_types.h"

void SPI_voidInitMaster(void);
void SPI_voidInitSlave(void);
u8   SPI_u8Transceive(u8 Copy_u8Data);

#endif