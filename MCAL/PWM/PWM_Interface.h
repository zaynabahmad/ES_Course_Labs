#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"
#include "PWM_private.h"
#include "PWM_config.h"

void PWM_Init(u8 Copy_u8PR2Value);
void PWM_SetDutyCycle(u8 Copy_u8DutyPercentage);
void PWM_Stop(void);