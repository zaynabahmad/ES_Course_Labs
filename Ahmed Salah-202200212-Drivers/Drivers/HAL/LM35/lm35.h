/**
 * @file    lm35.h
 * @brief   PIC16F87X HAL LM35 Temperature Sensor Driver Header
 * @details LM35 outputs 10mV/°C linear voltage on an analog pin.
 *          Uses MCAL ADC for measurement.
 *
 * LM35 Specifications:
 *   Output: 10mV per °C
 *   Range:  −55°C to +150°C (LM35C/LM35CA)
 *           +2°C to +150°C  (LM35D — single supply, no negative)
 *   Accuracy: ±0.5°C at 25°C
 *
 * Conversion:
 *   Voltage(mV) = ADC_Value × (Vref_mV / 1024)
 *   Temp(°C)    = Voltage(mV) / 10
 *   Temp_Cx10   = ADC_Value × Vref_mV / 1024   (0.1°C resolution, integer)
 */

#ifndef LM35_H
#define LM35_H

#include "../../MCAL/ADC/adc.h"

/*============================================================
 * Default Reference Voltage (millivolts)
 *============================================================*/
#define LM35_DEFAULT_VREF_MV    5000u   /* 5V supply */

/*============================================================
 * Configuration Structure
 *============================================================*/
typedef struct {
    ADC_Channel_t  channel;     /* ADC channel connected to LM35 output  */
    uint16_t       vrefMv;      /* Reference voltage in mV (default 5000) */
} LM35_Config_t;

/*============================================================
 * Sensor Handle — stores runtime info
 *============================================================*/
typedef struct {
    ADC_Channel_t  channel;
    uint16_t       vrefMv;
} LM35_Handle_t;

/*============================================================
 * API
 *============================================================*/

/**
 * @brief  Initialize LM35 sensor
 * @param  handle  Pointer to LM35_Handle_t (filled by this function)
 * @param  cfg     Pointer to LM35_Config_t
 * @note   ADC must be initialized separately via ADC_Init() before using
 *         LM35 read functions. This function only stores the config.
 */
void LM35_Init(LM35_Handle_t *handle, const LM35_Config_t *cfg);

/**
 * @brief  Read raw 10-bit ADC value from LM35
 * @param  handle  Pointer to initialized LM35_Handle_t
 * @return 10-bit ADC result (0–1023)
 */
uint16_t LM35_ReadRaw(const LM35_Handle_t *handle);

/**
 * @brief  Read temperature in °C (integer, truncated)
 * @param  handle  Pointer to initialized LM35_Handle_t
 * @return Temperature in whole degrees Celsius
 * @note   Uses blocking ADC read
 */
uint16_t LM35_ReadTempC(const LM35_Handle_t *handle);

/**
 * @brief  Read temperature × 10 for 0.1°C resolution
 * @param  handle  Pointer to initialized LM35_Handle_t
 * @return Temperature × 10 (e.g., 235 = 23.5°C)
 * @note   Integer math only — no floating point
 */
uint16_t LM35_ReadTempCx10(const LM35_Handle_t *handle);

/**
 * @brief  Read temperature in °F (integer, truncated)
 * @param  handle  Pointer to initialized LM35_Handle_t
 * @return Temperature in whole degrees Fahrenheit
 * @note   Formula: °F = (°C × 9/5) + 32
 */
uint16_t LM35_ReadTempF(const LM35_Handle_t *handle);

/**
 * @brief  Read voltage in millivolts from LM35 output
 * @param  handle  Pointer to initialized LM35_Handle_t
 * @return Voltage in mV
 */
uint16_t LM35_ReadVoltageMv(const LM35_Handle_t *handle);

#endif /* LM35_H */
