#ifndef ADC_CONFIG_H
#define ADC_CONFIG_H

/* ADCON1: ADFM=1, VCFG1:VCFG0=00, PCFG3:PCFG0=1110 (AN0 analog) */
#define ADCON1_CONFIG_VALUE   0x8E

/* ADCON0 clock select bits ADCS1:ADCS0 (bits 7:6) */
#define ADC_CLOCK_SELECT      0x80  /* Fosc/32 */

#endif
