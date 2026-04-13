#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/* ADC Channels */
#define ADC_CHANNEL0    0
#define ADC_CHANNEL1    1
#define ADC_CHANNEL2    2
#define ADC_CHANNEL3    3
#define ADC_CHANNEL4    4
#define ADC_CHANNEL5    5
#define ADC_CHANNEL6    6
#define ADC_CHANNEL7    7
#define ADC_CHANNEL8    8
#define ADC_CHANNEL9    9
#define ADC_CHANNEL10   10
#define ADC_CHANNEL11   11
#define ADC_CHANNEL12   12
#define ADC_CHANNEL13   13

/* ADC Resolution */
#define ADC_8BIT_RESOLUTION     0
#define ADC_10BIT_RESOLUTION    1

/* ADC Voltage Reference */
#define ADC_REF_VSS_VDD         0   /* VSS and VDD */
#define ADC_REF_VSS_VREF        1   /* VSS and VREF+ */
#define ADC_REF_VREF_VDD        2   /* VREF- and VDD */
#define ADC_REF_VREF_VREF       3   /* VREF- and VREF+ */

/* ADC Initialization */
void ADC_Init(u8 resolution, u8 voltageRef);

/* Start ADC conversion on specified channel */
void ADC_StartConversion(u8 channel);

/* Check if ADC conversion is complete */
u8 ADC_IsConversionDone(void);

/* Read ADC value (8-bit or 10-bit depending on configuration) */
u16 ADC_ReadValue(void);

/* Blocking read ADC value */
u16 ADC_ReadChannel(u8 channel);

/* Set ADC interrupt callback */
void ADC_SetCallback(void (*Callback)(u16));

/* ADC Interrupt Service Routine (called from Interrupt_Manager) */
void ADC_ISR(void);

#endif
