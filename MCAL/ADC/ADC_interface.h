#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

#include "../../SERVICES/std_types.h"

#define ADC_CHANNEL0  0
#define ADC_CHANNEL1  1

void ADC_voidInit(void);
u16  ADC_u16ReadChannel(u8 Copy_u8Channel);

#endif