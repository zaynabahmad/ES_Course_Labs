/**
 * @file    lm35.c
 * @brief   PIC16F87X HAL LM35 Temperature Sensor Driver Implementation
 */

#include "lm35.h"

/*------------------------------------------------------------
 * LM35_Init
 *------------------------------------------------------------*/
void LM35_Init(LM35_Handle_t *handle, const LM35_Config_t *cfg)
{
    handle->channel = cfg->channel;
    handle->vrefMv  = cfg->vrefMv;

    /* If vrefMv was not set (zero), use default 5V */
    if (handle->vrefMv == 0u) {
        handle->vrefMv = LM35_DEFAULT_VREF_MV;
    }
}

/*------------------------------------------------------------
 * LM35_ReadRaw — blocking 10-bit ADC read
 *------------------------------------------------------------*/
uint16_t LM35_ReadRaw(const LM35_Handle_t *handle)
{
    return ADC_Read(handle->channel);
}

/*------------------------------------------------------------
 * LM35_ReadVoltageMv
 * Voltage(mV) = ADC × Vref_mV / 1024
 *------------------------------------------------------------*/
uint16_t LM35_ReadVoltageMv(const LM35_Handle_t *handle)
{
    uint16_t adcVal = ADC_Read(handle->channel);
    /* Use uint32_t to avoid overflow: max = 1023 × 5000 = 5,115,000 */
    uint32_t voltageMv = ((uint32_t)adcVal * (uint32_t)handle->vrefMv) / 1024u;
    return (uint16_t)voltageMv;
}

/*------------------------------------------------------------
 * LM35_ReadTempCx10 — temperature × 10
 * LM35 output = 10mV/°C
 * Temp_Cx10 = Voltage(mV) / 10 × 10 = Voltage(mV)
 *           = ADC × Vref_mV / 1024
 *
 * But we want 0.1°C resolution:
 *   Temp(°C) = Voltage(mV) / 10
 *   Temp_Cx10 = Voltage(mV)   (since 1mV = 0.1°C)
 *
 * Wait — let's be precise:
 *   Voltage(mV) = ADC × Vref_mV / 1024
 *   Temp(°C) = Voltage(mV) / 10.0
 *   Temp_Cx10 = Voltage(mV) / 10 × 10 = Voltage(mV)
 *
 * Actually:
 *   Temp_Cx10 = Temp(°C) × 10 = Voltage(mV) / 10 × 10 = Voltage(mV)
 *
 * So Temp × 10 is simply the voltage in mV.
 * E.g., 235mV → 23.5°C → Cx10 = 235
 *------------------------------------------------------------*/
uint16_t LM35_ReadTempCx10(const LM35_Handle_t *handle)
{
    return LM35_ReadVoltageMv(handle);
}

/*------------------------------------------------------------
 * LM35_ReadTempC — integer degrees
 * Temp(°C) = Voltage(mV) / 10
 *------------------------------------------------------------*/
uint16_t LM35_ReadTempC(const LM35_Handle_t *handle)
{
    uint16_t voltageMv = LM35_ReadVoltageMv(handle);
    return voltageMv / 10u;
}

/*------------------------------------------------------------
 * LM35_ReadTempF — Fahrenheit
 * °F = (°C × 9 / 5) + 32
 * To keep precision: use Cx10
 *   Fx10 = (Cx10 × 9 / 5) + 320
 *   F = Fx10 / 10
 *------------------------------------------------------------*/
uint16_t LM35_ReadTempF(const LM35_Handle_t *handle)
{
    uint16_t tempCx10 = LM35_ReadTempCx10(handle);
    /* Fx10 = (Cx10 × 9 / 5) + 320 */
    uint32_t tempFx10 = ((uint32_t)tempCx10 * 9u / 5u) + 320u;
    return (uint16_t)(tempFx10 / 10u);
}
