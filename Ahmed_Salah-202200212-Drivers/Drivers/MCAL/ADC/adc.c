/**
 * @file    adc.c
 * @brief   PIC16F877 ADC Driver Implementation
 */

#include "adc.h"

/* Acquisition time — Tad minimum ~1.6us at 5V; 2us safe */
/* At 4MHz Fosc each NOP = 250ns → 8 NOPs ≈ 2us           */
#define ADC_ACQUISITION_DELAY()  do { \
    __asm__("NOP"); __asm__("NOP"); __asm__("NOP"); __asm__("NOP"); \
    __asm__("NOP"); __asm__("NOP"); __asm__("NOP"); __asm__("NOP"); \
} while(0)

static ADC_Justify_t s_justify = ADC_JUSTIFY_RIGHT;

/*------------------------------------------------------------
 * ADC_Init
 *------------------------------------------------------------*/
void ADC_Init(const ADC_Config_t *cfg)
{
    s_justify = cfg->justify;

    /* ADCON1 — justification and pin configuration */
    ADCON1 = (uint8_t)(((uint8_t)cfg->justify << 7) | (uint8_t)(cfg->portCfg & 0x0Fu));

    /* ADCON0 — clock, channel 0 by default, ADC off initially */
    ADCON0 = (uint8_t)(((uint8_t)cfg->clock << 6) | (uint8_t)(ADC_CH0 << 3));

    /* Clear flag */
    PIR1bits.ADIF = 0;

    /* Interrupt enable (requires PEIE and GIE set externally) */
    if (cfg->intEnable == ADC_INT_ENABLE) {
        PIE1bits.ADIE = 1;
    } else {
        PIE1bits.ADIE = 0;
    }

    /* Turn on ADC */
    ADCON0bits.ADON = 1;
}

/*------------------------------------------------------------
 * ADC_Enable / Disable
 *------------------------------------------------------------*/
void ADC_Enable(void)
{
    ADCON0bits.ADON = 1;
}

void ADC_Disable(void)
{
    ADCON0bits.ADON = 0;
}

/*------------------------------------------------------------
 * ADC_SelectChannel
 * CHS<2:0> = bits<5:3> of ADCON0
 *------------------------------------------------------------*/
void ADC_SelectChannel(ADC_Channel_t channel)
{
    ADCON0 = (uint8_t)((ADCON0 & 0xC7u) | (uint8_t)((uint8_t)channel << 3));
    ADC_ACQUISITION_DELAY();   /* Allow capacitor to charge */
}

/*------------------------------------------------------------
 * ADC_StartConversion
 *------------------------------------------------------------*/
void ADC_StartConversion(void)
{
    ADCON0bits.GO_nDONE = 1;
}

/*------------------------------------------------------------
 * ADC_IsConversionDone
 *------------------------------------------------------------*/
uint8_t ADC_IsConversionDone(void)
{
    return (uint8_t)(ADCON0bits.GO_nDONE == 0u);
}

/*------------------------------------------------------------
 * ADC_GetResult
 * Right-justified: result = ADRESH<1:0> << 8 | ADRESL
 * Left-justified:  result = ADRESH << 2 | ADRESL >> 6
 *------------------------------------------------------------*/
uint16_t ADC_GetResult(void)
{
    uint16_t result;

    if (s_justify == ADC_JUSTIFY_RIGHT) {
        result = (uint16_t)(((uint16_t)(ADRESH & 0x03u) << 8u) | (uint16_t)ADRESL);
    } else {
        result = (uint16_t)(((uint16_t)ADRESH << 2u) | ((uint16_t)(ADRESL >> 6u)));
    }
    return result;
}

/*------------------------------------------------------------
 * ADC_Read  — blocking convenience function
 *------------------------------------------------------------*/
uint16_t ADC_Read(ADC_Channel_t channel)
{
    ADC_SelectChannel(channel);
    ADC_StartConversion();
    while (!ADC_IsConversionDone()) {
        /* Wait */
    }
    return ADC_GetResult();
}

/*------------------------------------------------------------
 * ADC_ClearFlag
 *------------------------------------------------------------*/
void ADC_ClearFlag(void)
{
    PIR1bits.ADIF = 0;
}

/*------------------------------------------------------------
 * Weak callback
 *------------------------------------------------------------*/
void __attribute__((weak)) ADC_ConvComplete_Callback(void)
{
    /* User implements */
}

/*============================================================
 * ISR dispatch (standalone; merge with project ISR)
 *============================================================*/
#ifdef ADC_USE_STANDALONE_ISR
void __interrupt() ADC_ISR(void)
{
    if (PIE1bits.ADIE && PIR1bits.ADIF) {
        PIR1bits.ADIF = 0;
        ADC_ConvComplete_Callback();
    }
}
#endif
