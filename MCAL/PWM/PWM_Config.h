#ifndef PWM_CONFIG_H
#define PWM_CONFIG_H

/* Frequency calculation based on Fosc = 4MHz and Timer 2 Prescaler = 16 */
/* PR2 = (Fosc / (4 * Fpwm * TMR2Prescale)) - 1 */
/* Example: For Fpwm = ~244Hz with Fosc=4MHz, PR2 = 255 */

#define PWM_PR2_VALUE 124

#endif