#ifndef PWM_CONFIG_H
#define PWM_CONFIG_H

/* Timer2 prescaler: PWM_PRESCALE_1, PWM_PRESCALE_4, or PWM_PRESCALE_16 */
#define PWM_TIMER2_PRESCALE   PWM_PRESCALE_16

/* PR2 value sets PWM period.
   Formula: PR2 = (Fosc / (4 * prescaler * freq_Hz)) - 1
   8 MHz Fosc, prescale=16, 1 kHz PWM -> PR2 = (8000000/(4*16*1000)) - 1 = 124 */
#define PWM_PR2_VALUE   124

#endif
