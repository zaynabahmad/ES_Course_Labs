/**
 * @file    PWM.c
 * @brief   CCP1 PWM driver implementation for the PIC16F877A.
 *
 * @details PR2 is cached after every frequency change because the duty-cycle
 *          maths needs it: duty is expressed as a fraction of the period, and
 *          the period is (PR2 + 1) steps. Caching avoids reading the SFR back
 *          and keeps vPWM_SetDuty() independent of bank selection.
 */
#include "PWM_interface.h"
#include "PWM_private.h"
#include "PWM_cfg.h"
#include "../SERVICES/Macros.h"

/** Last period value written to PR2 -- the denominator for duty scaling. */
static byte_t u8CachedPR2 = 0u;

/**
 * @brief  Translate the configured prescaler into its T2CON bit pattern.
 */
static byte_t u8PrescalerBits(void)
{
    switch (PWM_TMR2_PRESCALER)
    {
        case 1u:  return 0x00u;
        case 4u:  return 0x01u;
        case 16u: return 0x02u;
        default:  return 0x02u;         /* default to the widest divider. */
    }
}

void vPWM_Init(void)
{
    BIT_LOW(PWM_REG_TRISC, PWM_PIN_CCP1);       /* CCP1 pin must be output. */

    /* Lower nibble selects PWM mode; duty LSBs (bits 5:4) start at zero. */
    PWM_REG_CCP1CON = PWM_MODE_SELECT;

    /* Load the Timer2 prescaler field (bits 1:0); timer stays off via bit 2. */
    PWM_REG_T2CON = u8PrescalerBits();

    vPWM_SetFreq(PWM_DEFAULT_FREQ_HZ);
    vPWM_SetDuty(0u);
}

void vPWM_SetFreq(dword_t u32FreqHz)
{
    dword_t u32Period;

    if (u32FreqHz == 0uL)
    {
        return;                                 /* a 0 Hz request is a no-op. */
    }

    /* period steps = Fosc / (4 * prescaler * freq); the divide-by-4 and the
     * prescaler are merged into one shift/divide selected per prescaler. */
    switch (PWM_TMR2_PRESCALER)
    {
        case 1u:  u32Period = PWM_FOSC_HZ / (4uL  * u32FreqHz); break;
        case 4u:  u32Period = PWM_FOSC_HZ / (16uL * u32FreqHz); break;
        case 16u: u32Period = PWM_FOSC_HZ / (64uL * u32FreqHz); break;
        default:  u32Period = PWM_FOSC_HZ / (64uL * u32FreqHz); break;
    }

    /* PR2 holds period-1; guard the 8-bit field against an over-low freq. */
    if (u32Period == 0uL)
    {
        u8CachedPR2 = 0u;
    }
    else if (u32Period > 256uL)
    {
        u8CachedPR2 = 255u;
    }
    else
    {
        u8CachedPR2 = (byte_t)(u32Period - 1uL);
    }

    PWM_REG_PR2 = u8CachedPR2;
}

void vPWM_SetDuty(byte_t u8Percent)
{
    word_t u16DutyCount;

    if (u8Percent > 100u)
    {
        u8Percent = 100u;                       /* clamp to fully on. */
    }

    /* The 10-bit duty count spans 4 * (PR2 + 1) at full scale. Scale the
     * requested percentage into that range in 16-bit fixed point. */
    u16DutyCount = (word_t)(((dword_t)u8Percent *
                             ((dword_t)u8CachedPR2 + 1uL) * 4uL) / 100uL);

    /* Top 8 bits -> CCPR1L; bottom 2 bits -> CCP1CON<5:4>. */
    PWM_REG_CCPR1L = (byte_t)(u16DutyCount >> 2);
    PWM_REG_CCP1CON = (PWM_REG_CCP1CON & ~(0x03u << PWM_DUTY_LSB_SHIFT)) |
                      (byte_t)((u16DutyCount & 0x03u) << PWM_DUTY_LSB_SHIFT);
}

void vPWM_Start(void)
{
    BIT_HIGH(PWM_REG_T2CON, PWM_BIT_TMR2ON);
}

void vPWM_Stop(void)
{
    BIT_LOW(PWM_REG_T2CON, PWM_BIT_TMR2ON);
}
