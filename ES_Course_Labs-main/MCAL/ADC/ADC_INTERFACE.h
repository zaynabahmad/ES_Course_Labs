#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

#include "../../SERVICES/BIT_MATH.h"
#include "../../SERVICES/STD_TYPES.h"

// ================== CONFIG ==================

// ADC Channels (for future use)
#define ADC_CHANNEL_0   0
#define ADC_CHANNEL_1   1
#define ADC_CHANNEL_2   2
#define ADC_CHANNEL_3   3
#define ADC_CHANNEL_4   4
#define ADC_CHANNEL_5   5
#define ADC_CHANNEL_6   6
#define ADC_CHANNEL_7   7


// Initialize ADC module
void ADC_init(void);

// Start conversion and return result
u16 ADConversion(void);

// Select ADC channel
void ADC_SelectChannel(u8 channel);

#endif // ADC_INTERFACE_H