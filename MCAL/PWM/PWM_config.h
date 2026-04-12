#ifndef PWM_CONFIG_H
#define PWM_CONFIG_H

#include "../../SERVICES/STD_TYPES.h"

/* PWM Frequency Configuration */
#define PWM_FREQUENCY_HZ 5000 /* 5 kHz base frequency */

/* PWM Prescaler for Timer2 */
#define PWM_PRESCALER 1 /* 1, 4, or 16 */

/* Initial Duty Cycle */
#define PWM_CHANNEL1_INIT_DUTY 50 /* 50% */
#define PWM_CHANNEL2_INIT_DUTY 50 /* 50% */

#endif
