#ifndef PWM_CONFIG_H
#define PWM_CONFIG_H

/* PWM Frequency = Fosc / (4 * Prescaler * (PR2 + 1))
   Fosc = 4MHz, Prescaler = 1, PR2 = 124
   Frequency = 4000000 / (4 * 1 * 125) = 8000 Hz = 8KHz */

#define PWM_PR2_VALUE      124
#define PWM_PRESCALER      0x00   /* Prescaler 1:1 */

#endif