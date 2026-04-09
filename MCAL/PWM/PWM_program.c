#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "PWM_private.h"
#include "PWM_interface.h"

void PWM_voidInit(void)
{
    // PWM mode
    SET_BIT(CCP1CON,2);
    SET_BIT(CCP1CON,3);

    PR2 = 255;

    // Start Timer2
    SET_BIT(T2CON,2);
}

void PWM_voidSetDuty(unsigned char duty)
{
    CCPR1L = duty;
}