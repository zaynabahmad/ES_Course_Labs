#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"


void SPI_voidMasterInit(void);
u8 SPI_u8Transceive(u8 Copy_u8Data);
void SPI_voidWrite(u8 Copy_u8Data);
u8 SPI_u8Read(void);
void SPI_voidDisable(void);

#endif /* SPI_INTERFACE_H */