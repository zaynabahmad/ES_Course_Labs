#ifndef ADC_CONFIG_H
#define ADC_CONFIG_H

/*
 * ADC Configuration:
 * Right Justified Result
 */
#define ADC_RESULT_FORMAT  1   // 1 = Right, 0 = Left

/*
 * ADC Clock Selection:
 * Choose based on Fosc
 * Example: Fosc = 8 MHz ? Fosc/32
 */
#define ADC_CLOCK_SELECT   2   // Fosc/32

#endif