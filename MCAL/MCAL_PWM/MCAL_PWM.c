#include "../../MCAL/MCAL_PWM/MCAL_PWM_INTERFACE.h"

void PWM_Init(void) {
    PR2 = 249;
    CCP1CON = 0x0C;
    T2CON = 0x05;
}

void PWM_SetDutyCycle(unsigned char duty) {
    CCPR1L = duty/100 * PR2;
}