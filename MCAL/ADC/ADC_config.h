#ifndef ADC_CONFIG_H
#define ADC_CONFIG_H

/* A/D Port Configuration Control bits (ADCON1 Register)
 * Use this table to configure which pins are Analog and which are Digital, and Vref sources.
 * Example: 0x02 means AN0-AN4 are analog, AN5-AN7 are Vref, and PORTD is digital.
 * See datasheet page 136 for all options.
 */
#define ADC_PORT_CONFIG     0x0E  /* Sets AN0 as the only Analog Input */


/* A/D Clock Source Selection (ADCON0 Register)
 * Options: ADC_FOSC_2, ADC_FOSC_8, ADC_FOSC_32, ADC_FRC
 */
#define ADC_CLOCK_SOURCE    ADC_FOSC_32


/* A/D Result Format: ADC_RIGHT_JUSTIFIED or ADC_LEFT_JUSTIFIED (ADCON1 Register) */
#define ADC_RESULT_FORMAT   ADC_RIGHT_JUSTIFIED

#endif