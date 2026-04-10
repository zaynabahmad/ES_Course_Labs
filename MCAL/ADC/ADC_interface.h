#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/* ADC Channels (for PIC16F877A) */
#define ADC_CHANNEL_AN0 0
#define ADC_CHANNEL_AN1 1
#define ADC_CHANNEL_AN2 2
#define ADC_CHANNEL_AN3 3
#define ADC_CHANNEL_AN4 4
#define ADC_CHANNEL_AN5 5
#define ADC_CHANNEL_AN6 6
#define ADC_CHANNEL_AN7 7

/* ADC Reference Voltage */
#define ADC_VREF_VSS_VDD 0  /* VSS to VDD */
#define ADC_VREF_EXTERNAL 1 /* External reference */

/* ADC Conversion Modes */
#define ADC_MODE_SINGLE 0 /* Single channel conversion */
#define ADC_MODE_AUTO 1   /* Auto conversion */

/* Function Prototypes */
void ADC_Init(void);
void ADC_SelectChannel(u8 Channel);
void ADC_StartConversion(void);
u8 ADC_IsConversionComplete(void);
u16 ADC_GetResult(void);
u16 ADC_ReadChannel(u8 Channel);
void ADC_SetRefVoltage(u8 RefMode);

#endif
