#include "LM35_interface.h"

/* =========================================================
   LM35_Init
========================================================= */

void LM35_Init(void)
{
    ADC_Init();
}

/* =========================================================
   LM35_GetTemp
   Returns temperature in whole degrees Celsius (u16).
========================================================= */

u16 LM35_GetTemp(void)
{
    u16 adc_val = ADC_Read(LM35_ADC_CHANNEL);

    /* T(°C) = (ADC * Vref_mV) / (ADC_steps * mV_per_deg)
     *        = (ADC * 5000)    / (1024 * 10)
     *        = (ADC * 500)     / 1024                      */
    return (u16)((adc_val * (LM35_VREF_MV / LM35_MV_PER_DEG)) / LM35_ADC_STEPS);
}

/* =========================================================
   LM35_GetTempTenth
   Returns temperature in tenths of a degree Celsius.
   Example: 235 → 23.5 °C
========================================================= */

u16 LM35_GetTempTenth(void)
{
    u16 adc_val = ADC_Read(LM35_ADC_CHANNEL);

    /* T_tenth = (ADC * Vref_mV) / (ADC_steps * (mV_per_deg/10))
     *         = (ADC * 5000)    / 1024                            */
    return (u16)((adc_val * LM35_VREF_MV) / LM35_ADC_STEPS);
}