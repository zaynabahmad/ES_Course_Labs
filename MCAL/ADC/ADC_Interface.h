#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"
#include "ADC_Private.h"
#include "ADC_Config.h"

/* Channel definitions */
#define ADC_CHANNEL_0  0
#define ADC_CHANNEL_1  1
#define ADC_CHANNEL_2  2
#define ADC_CHANNEL_3  3
#define ADC_CHANNEL_4  4
#define ADC_CHANNEL_5  5
#define ADC_CHANNEL_6  6
#define ADC_CHANNEL_7  7

/* Initialize the ADC module */
void ADC_Init(void);

/* Read the analog value of a specific channel (Blocking/Polling) */
u16 ADC_ReadChannel(u8 Channel);

#endif