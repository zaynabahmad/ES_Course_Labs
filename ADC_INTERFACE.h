#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

#include "../SERVICES/STD_TYPES.h"

/* Channel IDs */
#define ADC_CH0   0
#define ADC_CH1   1
#define ADC_CH2   2
#define ADC_CH3   3
#define ADC_CH4   4
#define ADC_CH5   5
#define ADC_CH6   6
#define ADC_CH7   7

/* Clock options (ADCS1:ADCS0 in ADCON0) */
#define ADC_CLK_FOSC_2    0x00
#define ADC_CLK_FOSC_8    0x01
#define ADC_CLK_FOSC_32   0x02
#define ADC_CLK_FRC       0x03

/* Result justification */
#define ADC_RIGHT_JUSTIFIED  1
#define ADC_LEFT_JUSTIFIED   0

void ADC_Init(void);
u16  ADC_Read(u8 channel);

#endif
