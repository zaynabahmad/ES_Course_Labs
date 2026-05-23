#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

#include "D:\Uni\Y4 S2\Embedded Systems\Final\SERVICES\STD_TYPES.h"

#define ADC_INVALID_CHANNEL   0xFFFFu

void ADC_voidInit(void);

unsigned int ADC_u16Read(unsigned char channel);

float ADC_f32ToVoltage(unsigned int raw_value);

#endif /* ADC_INTERFACE_H */