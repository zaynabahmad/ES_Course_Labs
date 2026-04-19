 #include "../../SERVICES/std_types.h"
#include "../../SERVICES/bit_math.h"
#include "PWM_interface.h"
#include "PWM_private.h"

void PWM_voidInit(void) {
    /* Set RC2 as Output (CCP1 pin) */
    CLR_BIT(TRISC_REG, 2);
    /* Set PWM Period (PR2) */
    PR2_REG = 255;
    /* Configure CCP1 for PWM Mode */
    CCP1CON_REG = 0x0C;
    /* Timer2: Prescaler 1:16, Timer ON */
    T2CON_REG = 0x06;
}

void PWM_voidSetDutyCycle(u8 Copy_u8DutyCycle) {
    /* Duty Cycle calculation for 8-bit resolution */
    CCPR1L_REG = (u8)((u16)Copy_u8DutyCycle * 255 / 100);
}