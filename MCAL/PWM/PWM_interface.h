#ifndef PWM_INTERFACE_H
#define PWM_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"


 //  Duty-cycle level IDs (cycled by each button press)

#define PWM_DUTY_LEVEL_25     0u
#define PWM_DUTY_LEVEL_50     1u
#define PWM_DUTY_LEVEL_75     2u
#define PWM_DUTY_LEVEL_100    3u
#define PWM_DUTY_LEVELS_NUM   4u   /* total number of levels */


void PWM_Init(void);
void PWM_SetDutyLevel(u8 level);
void PWM_NextDutyLevel(void);

#endif
