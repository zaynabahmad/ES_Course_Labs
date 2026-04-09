#ifndef PWM_CONFIG_H
#define PWM_CONFIG_H

/* PWM Configuration */
/* CPU Frequency in Hz */
#define PWM_FOSC  4000000

/* Default PWM Frequency (Hz) - Can be overridden in PWM_Init() */
#define PWM_DEFAULT_FREQUENCY  5000  /* 5 kHz for autonomous car motor */

#endif
