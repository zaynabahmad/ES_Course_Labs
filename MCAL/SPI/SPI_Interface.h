#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

typedef struct
{
    u8 Mode;
    u8 ClockPolarity;
    u8 ClockPhase;
    u8 SampleAtEnd;
} SPI_ConfigType;

void SPI_Init(SPI_ConfigType *ConfigPtr);
u8 SPI_Transfer(u8 Data);

#endif
