#ifndef PWM_CONFIG_H
#define PWM_CONFIG_H

/* * Timer2 Prescaler for PWM 
 * Options: 1, 4, 16 
 */
#define PWM_TMR2_PRESCALER  16

/* * Calculate PR2 based on desired PWM Frequency
 * PWM Period = [(PR2) + 1] * 4 * TOSC * (TMR2 Prescale Value)
 * * Example: Fosc = 8 MHz, Prescaler = 16.
 * Target freq = 1 kHz (Period = 1000 us).
 * 1000 us = (PR2 + 1) * 4 * (0.125 us) * 16
 * 1000 = (PR2 + 1) * 8
 * PR2 + 1 = 125 -> PR2 = 124
 */
#define PWM_PR2_VALUE       124

#endif