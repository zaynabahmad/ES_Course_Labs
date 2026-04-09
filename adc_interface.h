#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

#include "../../SERVICES/types.h"

void ADC_Configure(void);
u16 ADC_GetConversion(u8 channel);

#endif