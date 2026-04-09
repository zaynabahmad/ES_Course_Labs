#include "../../SERVICES/std_types.h"
#include "../../SERVICES/bit_math.h"
#include "PWM_private.h"
#include "PWM_interface.h"

void PWM_voidInit(void) {
    /* Set RC2 as output */
    CLR_BIT(TRISC_REG, 2);
    /*  Set Period (PR2) */
    PR2_REG = 255;
    /*  Configure CCP1 for PWM mode */
    CCP1CON_REG = 0x0C;
    /*  Start Timer2 with Prescaler 4 */
    T2CON_REG = 0x05;
}

void PWM_voidSetDutyCycle(u8 copy_u8Duty) {
    /* Duty Cycle calculation (8-bit resolution for simplicity) */
    CCPR1L_REG = (u8)((copy_u8Duty * 255) / 100);
}