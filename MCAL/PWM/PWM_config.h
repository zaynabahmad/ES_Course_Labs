#ifndef PWM_CONFIG_H
#define PWM_CONFIG_H

/* PWM Configuration */
#define PWM_FREQUENCY        5000    /* PWM Frequency in Hz (5kHz) */
#define PWM_TIMER2_PRESCALE  1       /* Timer2 Prescaler: 1, 4, or 16 */
#define OSC_FREQ             8000000 /* Oscillator frequency: 8MHz */

/* PIC16F877A - PWM Pins */
#define PWM_CCP1_PIN  2  /* CCP1 on RC2 */
#define PWM_CCP2_PIN  1  /* CCP2 on RC1 */

#endif
