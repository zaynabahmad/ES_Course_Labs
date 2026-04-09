#ifndef PWM_CONFIG_H
#define PWM_CONFIG_H

/* Timer2 Prescaler configurations
   1 = 1:1
   4 = 1:4
   16 = 1:16
*/
#define PWM_PRESCALER        4

/* PWM Period Setting (PR2 Value) */
/* Formula: PR2 = (Fosc / (4 * Fpwm * Prescaler)) - 1 */
/* Example: For Fosc = 8MHz, Fpwm = 5kHz, Prescaler = 4 -> PR2 = 99 */
#define PWM_PR2_VALUE        99

#endif
