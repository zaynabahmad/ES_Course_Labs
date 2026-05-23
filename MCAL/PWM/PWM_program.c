#include "D:\Uni\Y4 S2\Embedded Systems\Final\SERVICES\STD_TYPES.h"
#include "D:\Uni\Y4 S2\Embedded Systems\Final\SERVICES\BIT_MATH.h"
#include "D:\Uni\Y4 S2\Embedded Systems\Final\MCAL\PWM\PWM_private.h"
#include "D:\Uni\Y4 S2\Embedded Systems\Final\MCAL\PWM\PWM_interface.h"

/* ---------------------------------------------------------- */
void PWM_voidInit(void)
{
    CLR_BIT(TRISC, PWM_OUTPUT_PIN);

    PR2 = PWM_PR2_VALUE;
    
    CCP1CON = PWM_MODE_VALUE;
    
    CCPR1L = 0x00u;

    TMR2   = 0x00u;                         /* clear timer count   */
    T2CON  = T2_PRESCALE_4;                 /* set prescaler = 1:4 */
    SET_BIT(T2CON, T2CON_TMR2ON);           /* start Timer2        */
}

/* ---------------------------------------------------------- */
unsigned char PWM_voidSetDuty(unsigned char duty_percent)
{
    unsigned int raw;

    /* Validate: duty cycle cannot exceed 100% */
    if (duty_percent > 100u)
    {
        return PWM_ERR_INVALID;
    }

    raw = ((unsigned int)duty_percent * PWM_MAX_DUTY) / 100u;


    CCPR1L = (unsigned char)raw;

    CLR_BIT(CCP1CON, CCP1CON_DC1B0);
    CLR_BIT(CCP1CON, CCP1CON_DC1B1);

    return PWM_OK;
}

/* ---------------------------------------------------------- */
void PWM_voidSetDutyRaw(unsigned char raw)
{

    CCPR1L = raw;
    CLR_BIT(CCP1CON, CCP1CON_DC1B0);
    CLR_BIT(CCP1CON, CCP1CON_DC1B1);
}

/* ---------------------------------------------------------- */
void PWM_voidStop(void)
{
    /* Disable Timer2 first to freeze the PWM timebase */
    CLR_BIT(T2CON, T2CON_TMR2ON);

    /* Clear CCP1CON mode bits ? CCP1 module off, pin goes LOW */
    CCP1CON = 0x00u;

    /* Set duty registers to 0 so next Init starts cleanly */
    CCPR1L = 0x00u;
}