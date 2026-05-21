#ifndef PWM_CONFIG_H
#define PWM_CONFIG_H

/* 8kHz PWM @ 8MHz, prescaler 1:1, PR2 = 249 */
#define PWM_FOSC            8000000UL
#define PWM_T2_PRESCALER    T2CKPS_1
#define PWM_T2_PRESCALER_VAL   1UL
#define PWM_DEFAULT_FREQ    8000UL

#define PWM_PR2_VALUE \
    ((u8)((PWM_FOSC / (4UL * PWM_DEFAULT_FREQ * PWM_T2_PRESCALER_VAL)) - 1UL))

#endif
