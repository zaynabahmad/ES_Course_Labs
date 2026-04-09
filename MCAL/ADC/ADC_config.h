#ifndef ADC_CONFIG_H
#define ADC_CONFIG_H

/* Result Format (ADFM bit)
   1 -> Right Justified (Required for 10-bit results in C)
   0 -> Left Justified */
#define ADC_RESULT_FORMAT       1

/* Clock Conversion (ADCS bits)
   0b10 -> Fosc/32 (Best for 8MHz oscillator to meet TAD timing) */
#define ADC_CLOCK_SELECT        0b10

/* Port Configuration (PCFG bits)
   0b1110 -> AN0 is Analog, Vref+ = VDD (5V), Vref- = VSS (0V) */
#define ADC_PORT_CONFIG         0b1110

#endif