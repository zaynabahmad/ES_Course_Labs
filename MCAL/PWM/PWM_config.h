#ifndef PWM_CONFIG_H
#define PWM_CONFIG_H

#include "../TIMER_2/Timer2_interface.h" /* Needed for prescaler options */

/* Define your CPU's oscillator frequency in Hz */
#ifndef FOSC
#define FOSC 4000000 
#endif

/* Desired PWM Frequency in Hz */
#define PWM_FREQUENCY_HZ 1000  /* 1 kHz */

/* Timer2 Prescaler Selection
 * Options: TIMER2_PRESCALER_1, TIMER2_PRESCALER_4, TIMER2_PRESCALER_16
 */
#define PWM_TMR2_PRESCALER TIMER2_PRESCALER_16

#endif