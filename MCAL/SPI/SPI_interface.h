#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/* Init */
void SPI_voidInitMaster(void);
void SPI_voidInitSlave(void);

/* Data */
u8 SPI_u8Transceive(u8 Copy_u8Data);

/* SS Control (Master) */
void SPI_voidSelectSlave(void);
void SPI_voidDeselectSlave(void);

#endif