#ifndef PWM_CONFIG_H
#define PWM_CONFIG_H

#include "PWM_interface.h"

/*  8 MHz crystal  →  Tosc = 0.125 µs
    Prescaler 1:4, PR2 = 99:
      PWM period = (99+1) × 4 × 0.125µs × 4 = 200 µs  →  5 kHz

    Duty cycle simplification (PR2=99, prescaler=4):
      DC_10bit     = percent × (PR2+1) × 4 / 100 = percent × 4
      CCPR1L       = DC_10bit >> 2 = percent
      CCP1CON<5:4> = DC_10bit & 0x03 = 0   (always zero for 25/50/75/100%)  */

#define PWM_PR2_VALUE      99u
#define PWM_PRESCALER      PWM_PRESCALER_4
#define PWM_INIT_DUTY_PCT  25u    /* initial duty cycle on power-up */

#endif
