#include "PWM_interface.h"
#include "PWM_private.h"
#include "PWM_config.h"
#include "../../SERVICES/BIT_MATH.h"

void PWM_Init(void)
{
    /* Step 1: Set PWM period (determines frequency) */
    PR2 = PWM_PR2_VALUE;

    /* Step 2: Set initial duty cycle — DC LSBs = 00, CCPR1L = percent */
    CCPR1L  = PWM_INIT_DUTY_PCT;
    CCP1CON = (CCP1CON & 0xCFu);              /* clear bits 5:4 (DC1B1:DC1B0)  */

    /* Step 3: Make RC2/CCP1 an output */
    CLR_BIT(TRISC, TRISC_CCP1PIN);

    /* Step 4: Enable Timer2 with chosen prescaler */
    T2CON = (1u << T2CON_TMR2ON) | (PWM_PRESCALER & 0x03u);

    /* Step 5: Configure CCP1 for PWM mode (bits 3:0 = 1100) */
    CCP1CON = (CCP1CON & 0xF0u) | CCP1_PWM_MODE;
}

void PWM_SetDutyCycle(u8 percent)
{
    /*  With PR2=99, prescaler=4:
          DC_10bit     = percent × 4
          CCPR1L       = DC_10bit >> 2 = percent
          CCP1CON<5:4> = DC_10bit & 0x03 = 0         */
    CCPR1L  = percent;
    CCP1CON = (CCP1CON & 0xCFu) | CCP1_PWM_MODE;    /* clear DC LSBs, keep mode */
}
