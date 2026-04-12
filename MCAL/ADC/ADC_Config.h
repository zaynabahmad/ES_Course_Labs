#ifndef ADC_CONFIG_H
#define ADC_CONFIG_H

/* Result Justification: ADC_RIGHT_JUSTIFIED or ADC_LEFT_JUSTIFIED */
#define ADC_RESULT_FORMAT    ADC_RIGHT_JUSTIFIED

/* Clock Source: ADC_CLOCK_FOSC_2, ADC_CLOCK_FOSC_8, ADC_CLOCK_FOSC_32, ADC_CLOCK_FRC */
#define ADC_CLOCK_SOURCE     ADC_CLOCK_FOSC_8

/* Number of analog pins: 0-8 (see PCFG table in datasheet) */
/* ADC_ANALOG_PINS_ALL = all 8 analog, ADC_ANALOG_PINS_4 = AN0-AN3 only */
#define ADC_ANALOG_CONFIG    ADC_ANALOG_PINS_ALL

#endif
