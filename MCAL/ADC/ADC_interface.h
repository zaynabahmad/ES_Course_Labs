#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

// Channel Definitions
#define ADC_CHANNEL_AN0     0
#define ADC_CHANNEL_AN1     1
#define ADC_CHANNEL_AN2     2

void ADC_Init(void);
u16 ADC_ReadChannel(u8 Channel);

#endif