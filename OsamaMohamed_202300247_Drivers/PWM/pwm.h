/*
 * pwm.h
 * PWM Driver for PIC16F877A using CCP1 module
 *
 * CCP1 PWM output pin: RC2/CCP1
 * Uses Timer2 as PWM time base.
 *
 * PWM Period  = (PR2 + 1) * 4 * Tosc * TMR2 Prescaler
 * PWM Freq    = F_CPU / (4 * (PR2+1) * prescaler)
 *
 * For F_CPU=8MHz, prescaler=4, PR2=199:
 *   F_PWM = 8000000 / (4 * 200 * 4) = 2500 Hz
 *
 * Duty cycle (10-bit): CCPR1L:CCP1CON<5:4>
 *   duty_count = (duty_percent / 100.0) * 4 * (PR2 + 1)
 */

#ifndef PWM_H
#define PWM_H

#include "../std_types.h"
#include <xc.h>

/*
 * PWM_init: configure CCP1 PWM mode
 * dutyCycle: 0 to 100 (percent)
 */
void PWM_CCP1_init   (uint8 dutyCycle_percent);
void PWM_CCP1_setDuty(uint8 dutyCycle_percent);
void PWM_CCP1_stop   (void);

#endif /* PWM_H */
