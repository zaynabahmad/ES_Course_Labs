#include "PWM_Interface.h"

void pwm_test_run(void) {
    PWM_Init();

    PWM_SetDutyCycle(50);
    PWM_Start();
}