#ifndef LM35_INTERFACE_H
#define LM35_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"
#include "../../MCAL/ADC/ADC_Interface.h"
#include "LM35_private.h"
#include "LM35_config.h"

/*
 * Initialise the ADC module for LM35 readings.
 * Call once at startup before using LM35_GetTemp().
 */
void LM35_Init(void);

/*
 * Read and return temperature in whole degrees Celsius.
 * Formula: T(°C) = (ADC * Vref_mV) / (ADC_steps * mV_per_deg)
 *                = (ADC * 5000) / (1024 * 10)
 *                = (ADC * 500) / 1024
 */
u16 LM35_GetTemp(void);

/*
 * Read and return temperature in tenths of a degree Celsius.
 * Example: 235 means 23.5 °C.
 * Formula: T_tenth = (ADC * 5000) / 1024
 *          (divide by 10 for whole °C, modulo 10 for fraction)
 */
u16 LM35_GetTempTenth(void);

#endif