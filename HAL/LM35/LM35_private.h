#ifndef LM35_PRIVATE_H
#define LM35_PRIVATE_H

/*
 * LM35 temperature sensor — output voltage details
 *
 *   Vout = 10 mV / °C   (linear, 0 °C → 0 V, 100 °C → 1.0 V)
 *
 * ADC conversion (10-bit, Vref = 5 V):
 *   1 LSB = 5000 mV / 1024 ≈ 4.883 mV
 *
 * Temperature (integer, °C):
 *   T = (ADC_count * 5000) / (1024 * 10)
 *     = (ADC_count * 500) / 1024
 *
 * Temperature (tenths of °C, for 1 decimal place):
 *   T_tenth = (ADC_count * 5000) / 1024
 *           → divide by 10 to get °C, remainder is tenths
 *
 * At 25 °C: Vout = 250 mV → ADC ≈ 51 counts
 */

/* ADC full-scale millivolts (Vref = 5 V) */
#define LM35_VREF_MV        5000UL

/* ADC resolution (10-bit) */
#define LM35_ADC_STEPS      1024UL

/* LM35 sensitivity: 10 mV per °C */
#define LM35_MV_PER_DEG     10UL

#endif