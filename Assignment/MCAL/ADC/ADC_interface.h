#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

#include "../SERVICES/STD_TYPES.h"

void ADC_voidInit(void);
u16 ADC_u16ReadChannel(u8 channel);

#endif