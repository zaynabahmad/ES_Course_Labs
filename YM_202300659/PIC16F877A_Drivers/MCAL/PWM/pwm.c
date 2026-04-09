/*
 * pwm.c
 * MCAL - PWM Driver Implementation for PIC16F877A
 * Uses Timer2 and CCP1/CCP2 modules
 */

#include "pwm.h"
#include "pwm_private.h"

/* Store PR2 value for duty cycle calculation */
static u8  _period    = 124;
static u8  _ccp1mode  = 0;
static u8  _ccp2mode  = 0;

void PWM_Init(PWM_Channel_t ch, PWM_Prescaler_t prescaler, u8 period)
{
    _period = period;

    /* Step 1: Configure CCP pin as output */
    if(ch == PWM_CHANNEL_1)
    {
        TRISC_REG &= ~(1 << 2);    /* RC2/CCP1 as output */
    }
    else
    {
        TRISC_REG &= ~(1 << 1);    /* RC1/CCP2 as output */
    }

    /* Step 2: Set PWM period in PR2 */
    PR2_REG = period;

    /* Step 3: Configure Timer2 */
    T2CON_REG = 0x00;              /* Clear T2CON */
    T2CON_REG |= ((prescaler & 0x03) << T2CON_T2CKPS0);

    /* Step 4: Clear TMR2 */
    TMR2_REG = 0x00;

    /* Step 5: Configure CCPxCON for PWM mode, zero duty cycle */
    if(ch == PWM_CHANNEL_1)
    {
        CCP1CON_REG = CCP_PWM_MODE;
        CCPR1L_REG  = 0;
        _ccp1mode   = CCP_PWM_MODE;
    }
    else
    {
        CCP2CON_REG = CCP_PWM_MODE;
        CCPR2L_REG  = 0;
        _ccp2mode   = CCP_PWM_MODE;
    }

    /* Step 6: Enable Timer2 */
    T2CON_REG |= (1 << T2CON_TMR2ON);
}

void PWM_SetDuty(PWM_Channel_t ch, u16 dutyCycle)
{
    u8 ccprL, dcBits;

    /* dutyCycle is 10-bit: [9:2] go to CCPRxL, [1:0] go to DCxB1:DCxB0 */
    if(dutyCycle > 1023) dutyCycle = 1023;

    ccprL  = (u8)(dutyCycle >> 2);          /* Upper 8 bits */
    dcBits = (u8)(dutyCycle & 0x03) << 4;   /* Lower 2 bits shifted to pos 5:4 */

    if(ch == PWM_CHANNEL_1)
    {
        CCPR1L_REG  = ccprL;
        CCP1CON_REG = (CCP_PWM_MODE) | dcBits;
    }
    else
    {
        CCPR2L_REG  = ccprL;
        CCP2CON_REG = (CCP_PWM_MODE) | dcBits;
    }
}

void PWM_SetDutyPercent(PWM_Channel_t ch, u8 percent)
{
    u16 duty;
    if(percent > 100) percent = 100;
    duty = (u16)((u32)percent * 1023 / 100);
    PWM_SetDuty(ch, duty);
}

void PWM_Stop(PWM_Channel_t ch)
{
    if(ch == PWM_CHANNEL_1)
    {
        CCP1CON_REG = 0x00;     /* Disable CCP1 module */
        TRISC_REG   &= ~(1 << 2);
        /* Drive RC2 low */
        (*((volatile unsigned char*)0x07)) &= ~(1 << 2);
    }
    else
    {
        CCP2CON_REG = 0x00;
        TRISC_REG   &= ~(1 << 1);
        (*((volatile unsigned char*)0x07)) &= ~(1 << 1);
    }
}

void PWM_Start(PWM_Channel_t ch)
{
    if(ch == PWM_CHANNEL_1)
    {
        CCP1CON_REG = _ccp1mode ? _ccp1mode : CCP_PWM_MODE;
    }
    else
    {
        CCP2CON_REG = _ccp2mode ? _ccp2mode : CCP_PWM_MODE;
    }
    T2CON_REG |= (1 << T2CON_TMR2ON);
}
