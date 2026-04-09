#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"

#include "PWM_private.h"
#include "PWM_config.h"
#include "PWM_interface.h"

void PWM_voidInit(void)
{
    /* 1. Set the PWM Period (Frequency) */
    PR2 = PWM_PR2_VALUE;

    /* 2. Configure CCP1 Module for PWM Mode (Bits 2 and 3 = 1) */
    SET_BIT(CCP1CON, CCP1CON_CCP1M2);
    SET_BIT(CCP1CON, CCP1CON_CCP1M3);

    /* 3. Start with 0% Duty Cycle */
    CCPR1L = 0;
    CCP1CON &= 0b11001111; /* Clear bits 4 and 5 */

    /* 4. Turn ON Timer2 with Prescaler 16 */
    /* T2CON: Prescaler bits 1:0 = 1x (value 2 or 3 is 1:16) */
    T2CON |= 0b00000010; 
    SET_BIT(T2CON, T2CON_TMR2ON);
}

void PWM_voidSetDutyCycle(u8 Copy_u8DutyCyclePercent)
{
    u16 Local_u16DutyValue;

    /* Cap the input at 100% to prevent overflow */
    if (Copy_u8DutyCyclePercent > 100)
    {
        Copy_u8DutyCyclePercent = 100;
    }

    /* * Calculate 10-bit value (0-1023) from percentage (0-100).
     * Max Value = (PR2 + 1) * 4 = (255 + 1) * 4 = 1024
     */
    Local_u16DutyValue = ((u16)Copy_u8DutyCyclePercent * 1023) / 100;


    /* Shift right by 2 to grab the top 8 bits */
    CCPR1L = (u8)(Local_u16DutyValue >> 2);

    /* Clear bits 4 and 5 in CCP1CON, then insert the bottom 2 bits */
    CCP1CON &= 0b11001111;
    CCP1CON |= ((Local_u16DutyValue & 0x03) << 4);
}

void PWM_voidStop(void)
{
    /* Clear PWM Mode bits to shut off the CCP1 module */
    CLR_BIT(CCP1CON, CCP1CON_CCP1M2);
    CLR_BIT(CCP1CON, CCP1CON_CCP1M3);
}