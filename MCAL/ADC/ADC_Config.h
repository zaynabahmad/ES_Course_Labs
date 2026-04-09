#ifndef ADC_CONFIG_H
#define ADC_CONFIG_H

/* ADC Clock: ADC_FOSC_2, ADC_FOSC_8, ADC_FOSC_32, ADC_FRC */
#define ADC_CLK_SRC         ADC_FOSC_8

/* Result Justification: ADC_RIGHT_JUSTIFY, ADC_LEFT_JUSTIFY */
#define ADC_JUSTIFY         ADC_RIGHT_JUSTIFY

/* Port Configuration (PCFG3:PCFG0 of ADCON1)
   0x0E = AN0 analog, rest digital (common for single pot)
   0x00 = All analog (AN0-AN7)
   See datasheet Table 11-1 for full options */
#define ADC_PORT_CONFIG     0x00

#endif
