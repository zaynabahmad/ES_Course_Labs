#ifndef PWM_CONFIG_H
#define PWM_CONFIG_H

#define FOSC          4000000UL   /* CPU frequency */
#define PWM_FREQUENCY 1000UL      /* Desired PWM frequency in Hz */

/* Prescaler value: 1, 4, or 16 */
#define PWM_PRESCALER 16

/* PR2 = (Fosc / (4 * Prescaler * Fpwm)) - 1 */
#define PWM_PR2_VALUE  ((FOSC / (4UL * PWM_PRESCALER * PWM_FREQUENCY)) - 1)

#endif
