/*
 * adc.c
 * ADC Driver for PIC16F877A (10-bit, polling)
 */

#include "adc.h"
#include "../common_macros.h"

void ADC_init(const ADC_Config *config) {
    /* ADCON1: result right-justified (ADFM=1), configure analog pins
       0x8E => ADFM=1, all PORTA pins digital except AN0 (set per channel later)
       Use 0x80 to keep ADFM=1 and let channel selection handle pin config      */
    ADCON1 = 0x80;   /* ADFM=1, Vref = VDD/VSS, all pins analog by default    */

    if (config->vref == ADC_VREF_EXT)
        ADCON1 = 0x88;  /* ADFM=1, external Vref on RA3+/RA2- */

    /* ADCON0: clock select, channel=0, ADC off initially */
    ADCON0 = (uint8)((config->clock & 0x07) << 6);

    /* Enable ADC */
    ADCON0bits.ADON = 1;
}

uint16 ADC_readChannel(uint8 channel) {
    /* Select channel: CHS2:CHS0 in ADCON0 bits 5:3 */
    ADCON0 = (ADCON0 & 0xC7) | (uint8)((channel & 0x07) << 3);

    /* Acquisition delay: min 20 us for 8 MHz */
    __delay_us(20);

    /* Start conversion */
    ADCON0bits.GO_nDONE = 1;

    /* Wait for conversion complete (GO_nDONE goes 0) */
    while (ADCON0bits.GO_nDONE);

    /* Return 10-bit result (right-justified) */
    return (uint16)(((uint16)ADRESH << 8) | ADRESL);
}

void ADC_deInit(void) {
    ADCON0bits.ADON = 0;
    ADCON0 = 0x00;
    ADCON1 = 0x06;  /* All digital after deinit */
}
