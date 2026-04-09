/*
 * adc_test.h
 * APP Layer - ADC Test Declarations
 */

#ifndef ADC_TEST_H
#define ADC_TEST_H

typedef unsigned char  u8;
typedef unsigned int   u16;

void ADC_Test_Init(void);
void ADC_Test_DisplayOnLEDs(u16 adcValue);
void ADC_Test_ReadPotentiometer(void);
void ADC_Test_ReadTemperature(void);
void ADC_Test_Run(void);

#endif /* ADC_TEST_H */
