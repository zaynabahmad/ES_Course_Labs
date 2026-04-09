#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"
#include "ADC_Private.h"
#include "ADC_Config.h"

/* Channel Select */
#define ADC_CH0     0
#define ADC_CH1     1
#define ADC_CH2     2
#define ADC_CH3     3
#define ADC_CH4     4
#define ADC_CH5     5
#define ADC_CH6     6
#define ADC_CH7     7

/* Clock Source */
#define ADC_FOSC_2      0
#define ADC_FOSC_8      1
#define ADC_FOSC_32     2
#define ADC_FRC          3

/* Justification */
#define ADC_RIGHT_JUSTIFY  1
#define ADC_LEFT_JUSTIFY   0

void ADC_Init(void);
u16  ADC_Read(u8 Channel);
void ADC_StartConversion(u8 Channel);
u8   ADC_IsConversionDone(void);
u16  ADC_GetResult(void);

#endif
