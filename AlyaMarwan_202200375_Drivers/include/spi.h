#ifndef SPI_H
#define SPI_H

#include "spi_cfg.h"

void SPI_Init(void);
void SPI_SelectSlave(void);
void SPI_DeselectSlave(void);
int  SPI_Transceive(void);

#endif