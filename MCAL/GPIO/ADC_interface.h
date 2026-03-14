#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

#include "../SERVICES/STD_TYPES.h"

/* Channel IDs */
#define ADC_CHANNEL0    0
#define ADC_CHANNEL1    1
#define ADC_CHANNEL2    2
#define ADC_CHANNEL3    3
#define ADC_CHANNEL4    4
#define ADC_CHANNEL5    5
#define ADC_CHANNEL6    6
#define ADC_CHANNEL7    7

void ADC_Init(void);
u16  ADC_Read(u8 Channel);

#endif