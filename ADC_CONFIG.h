#ifndef ADC_CONFIG_H
#define ADC_CONFIG_H

/* Conversion clock: ADC_CLK_FOSC_2, ADC_CLK_FOSC_8,
                     ADC_CLK_FOSC_32, or ADC_CLK_FRC
   At 8 MHz: Fosc/32 gives Tad=4 us (min required: 1.6 us per datasheet) */
#define ADC_CLOCK_SELECT   ADC_CLK_FOSC_32

/* Result format: ADC_RIGHT_JUSTIFIED or ADC_LEFT_JUSTIFIED */
#define ADC_RESULT_FORMAT  ADC_RIGHT_JUSTIFIED

/* PCFG bits: 0x00 = all AN0..AN7 analog, Vref=VDD/VSS */
#define ADC_PCFG_VALUE     0x00

#endif
