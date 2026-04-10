#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/* Initialize as Master */
void SPI_Master_Init(void);

/* Initialize as Slave */
void SPI_Slave_Init(void);

/* Transmit and Receive simultaneously */
uint8 SPI_Exchange(uint8 data);

#endif