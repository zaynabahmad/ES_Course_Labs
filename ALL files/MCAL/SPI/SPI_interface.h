#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/*
 * Initialize SPI (Master mode)
 */
void SPI_Init(void);

/*
 * Send and receive one byte
 */
u8 SPI_Transceive(u8 Data);

#endif