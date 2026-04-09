#ifndef ADC_INTERFACE_H
#define ADC_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/* Clock Source Options */
#define ADC_FOSC_2   0b00
#define ADC_FOSC_8   0b01
#define ADC_FOSC_32  0b10
#define ADC_FRC      0b11

/* Result Format Options */
#define ADC_RIGHT_JUSTIFIED 1
#define ADC_LEFT_JUSTIFIED  0

/* Analog Channel Selections */
#define ADC_CHANNEL_AN0   0
#define ADC_CHANNEL_AN1   1
#define ADC_CHANNEL_AN2   2
#define ADC_CHANNEL_AN3   3
#define ADC_CHANNEL_AN4   4
#define ADC_CHANNEL_AN5   5
#define ADC_CHANNEL_AN6   6
#define ADC_CHANNEL_AN7   7

/* Function Prototypes */
void ADC_Init(void);
u16  ADC_Read(u8 channel);

#endif