/*
 * adc.c
 * MCAL - ADC Driver Implementation for PIC16F877A
 */

#include "adc.h"
#include "adc_private.h"

/* Store clock and justify settings for channel switching */
static u8 _adcon0_base = 0;

/* Small acquisition delay (~20us at 4MHz) */
static void ADC_AcqDelay(void)
{
    u8 i;
    for(i = 0; i < 20; i++)
    {
        /* ~1us per iteration at 4MHz */
        asm nop;
    }
}

void ADC_Init(ADC_Clock_t clk, ADC_Justify_t justify, ADC_PortConfig_t config)
{
    /* Configure ADCON1: result justification + port config */
    ADCON1_REG = 0x00;
    if(justify == ADC_RIGHT_JUSTIFIED)
    {
        ADCON1_REG |= (1 << ADCON1_ADFM);
    }
    ADCON1_REG |= (config & 0x0F);

    /* Configure ADCON0: clock + enable */
    _adcon0_base = (u8)((clk & 0x03) << 6);
    ADCON0_REG   = _adcon0_base | (1 << ADCON0_ADON);

    /* Set analog pins as inputs */
    TRISA_REG |= 0x3F;   /* RA0-RA5 as inputs */
}

void ADC_Enable(void)
{
    ADCON0_REG |= (1 << ADCON0_ADON);
}

void ADC_Disable(void)
{
    ADCON0_REG &= ~(1 << ADCON0_ADON);
}

void ADC_SelectChannel(ADC_Channel_t ch)
{
    /* Clear channel bits [5:3] then set */
    ADCON0_REG &= ~(0x07 << ADCON0_CHS0);
    ADCON0_REG |= ((ch & 0x07) << ADCON0_CHS0);
    /* Acquisition delay */
    ADC_AcqDelay();
}

void ADC_StartConversion(void)
{
    ADCON0_REG |= (1 << ADCON0_GO);
}

u8 ADC_IsConversionDone(void)
{
    /* GO/DONE bit clears when conversion complete */
    return !((ADCON0_REG >> ADCON0_GO) & 0x01);
}

u16 ADC_Read(ADC_Channel_t ch)
{
    u16 result;

    ADC_SelectChannel(ch);
    ADC_StartConversion();

    /* Wait for conversion to finish */
    while(!ADC_IsConversionDone());

    /* Read 10-bit result (right justified assumed) */
    result = (u16)(ADRESH_REG & 0x03) << 8;
    result |= (u16)ADRESL_REG;

    return result;
}
