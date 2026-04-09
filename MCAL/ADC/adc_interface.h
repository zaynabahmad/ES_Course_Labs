#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

#include "D:/ES-Project-Lab/SERVICES/std_types.h"

#define ADC_CHANNEL_0   0
#define ADC_CHANNEL_1   1
#define ADC_CHANNEL_2   2
#define ADC_CHANNEL_3   3
#define ADC_CHANNEL_4   4
#define ADC_CHANNEL_5   5
#define ADC_CHANNEL_6   6
#define ADC_CHANNEL_7   7

void ADC_Init(void);
u16 ADC_Read(u8 channel);

#endif