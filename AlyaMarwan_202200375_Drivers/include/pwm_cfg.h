#ifndef PWM_CFG_H
#define PWM_CFG_H

/* Timer2 prescaler options */
#define PWM_PRESCALER_1     0
#define PWM_PRESCALER_4     1
#define PWM_PRESCALER_16    2

/* PWM configuration for ~5kHz at 8MHz */
#define PWM_PRESCALER       PWM_PRESCALER_4
#define PWM_PR2             99

#endif