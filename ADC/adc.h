// Purpose: Lists ADC (analog sensor reading) functions

#ifndef ADC_H
#define ADC_H

#include "std_types.h"
#include "pic_config.h"

// Which pin to read from
typedef enum {
    ADC_CHANNEL_0 = 0,  // RA0/AN0
    ADC_CHANNEL_1,      // RA1/AN1
    ADC_CHANNEL_2,      // RA2/AN2
    ADC_CHANNEL_3,      // RA3/AN3
    ADC_CHANNEL_4,      // RA5/AN4
    ADC_CHANNEL_5,      // RE0/AN5
    ADC_CHANNEL_6,      // RE1/AN6
    ADC_CHANNEL_7       // RE2/AN7
} ADC_Channel;

void ADC_Init(void);                          // Setup ADC
uint16 ADC_Read(ADC_Channel channel);         // Read value (0-1023)
float ADC_ReadVoltage(ADC_Channel channel);   // Read voltage (0-5V)

#endif