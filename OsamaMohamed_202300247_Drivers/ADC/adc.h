/*
 * adc.h
 * ADC Driver for PIC16F877A (10-bit, polling)
 *
 * ADC pins: AN0-AN7 (shared with PORTA and PORTE)
 * Result: right-justified (ADFM=1) => ADRESH:ADRESL gives 10-bit value
 *
 * Conversion time must be >= 12 TAD
 * TAD = 1/F_ADC;  F_ADC depends on ADCS bits in ADCON0
 * For F_CPU=8MHz, ADCS=10 (Fosc/32): TAD = 4us  (min TAD = 1.6us) ✓
 */

#ifndef ADC_H
#define ADC_H

#include "../std_types.h"
#include <xc.h>

typedef enum {
    ADC_FOSC_2   = 0b000,
    ADC_FOSC_8   = 0b001,
    ADC_FOSC_32  = 0b010,
    ADC_FRC      = 0b011,   /* Internal RC oscillator */
    ADC_FOSC_4   = 0b100,
    ADC_FOSC_16  = 0b101,
    ADC_FOSC_64  = 0b110
} ADC_ClockSelect;

typedef enum {
    ADC_VREF_VDD_VSS = 0,  /* Vref+ = VDD, Vref- = VSS (default) */
    ADC_VREF_EXT     = 1   /* External Vref on RA3(+) and RA2(-)  */
} ADC_VrefMode;

typedef struct {
    ADC_ClockSelect clock;
    ADC_VrefMode    vref;
} ADC_Config;

void   ADC_init         (const ADC_Config *config);
uint16 ADC_readChannel  (uint8 channel);  /* channel: 0-7 */
void   ADC_deInit       (void);

#endif /* ADC_H */
