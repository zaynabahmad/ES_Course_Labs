#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

#include "../../SERVICES/BIT_MATH.h"
#include "../../SERVICES/STD_TYPES.h"


void ADC_Init(void);
u16 ADC_Read(u8 channel);

#endif