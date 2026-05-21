#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"
#include "../GPIO/GPIO_interface.h"
#include "SPI_Private.h"
#include "SPI_Config.h"

void SPI_MasterInit(void);
u8   SPI_Transceive(u8 Data);
void SPI_Write(u8 Data);
u8   SPI_Read(void);
void SPI_Disable(void);

#endif
