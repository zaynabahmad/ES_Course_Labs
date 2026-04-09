#ifndef ADC_CONFIG_H
#define ADC_CONFIG_H

/* ADC Configuration */
#define ADC_FOSC  4000000

/* ADC Conversion Clock */
/* ADCS<1:0>: 00 = Fosc/2, 01 = Fosc/8, 10 = Fosc/32, 11 = FRC */
#define ADC_CLOCK_FOSC_2   0  /* Fast clock */
#define ADC_CLOCK_FOSC_8   1  /* Standard */
#define ADC_CLOCK_FOSC_32  2  /* Slow clock */
#define ADC_CLOCK_FRC      3  /* Internal RC */

#define ADC_CLOCK_SELECT  ADC_CLOCK_FOSC_8  /* 4MHz/8 = 500kHz */

/* ADC Resolution */
#define ADC_RESOLUTION  10  /* 10-bit (0-1023) */

#endif
