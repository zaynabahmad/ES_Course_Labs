#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

#include "../../SERVICES/std_types.h"

/* Channel Definitions */
#define ADC_CH0    0
#define ADC_CH1    1
#define ADC_CH2    2
#define ADC_CH3    3
#define ADC_CH4    4
#define ADC_CH5    5
#define ADC_CH6    6
#define ADC_CH7    7

void ADC_voidInit(void);
u16  ADC_u16ReadChannel(u8 copy_u8Channel);

#endif