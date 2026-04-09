#ifndef PWM_CONFIG_H
#define PWM_CONFIG_H

/* Timer2 Prescaler: PWM_T2_PRE_1, PWM_T2_PRE_4, PWM_T2_PRE_16 */
#define PWM_T2_PRESCALER    PWM_T2_PRE_4

/* PWM Frequency via PR2:
   PWM Period = [(PR2)+1] * 4 * Tosc * (TMR2 Prescaler)
   For Fosc=4MHz, Prescaler=4, PR2=249 -> PWM freq = 1kHz */
#define PWM_PR2_VALUE       249

#endif
