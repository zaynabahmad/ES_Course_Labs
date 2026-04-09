#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

#include "../../SERVICES/types.h"

void SPI_Configure(void);
u8 SPI_ExchangeByte(u8 data_out);

#endif