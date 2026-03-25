/**
 * @file    pwm.c
 * @brief   PIC16F877 PWM Driver Implementation
 */

#include "pwm.h"

/* CCP PWM mode: CCP1M<3:0> = 1100 */
#define CCP_PWM_MODE   0x0Cu

/*------------------------------------------------------------
 * Internal: Configure Timer2 (shared by both CCP channels)
 *------------------------------------------------------------*/
static void pwm_timer2_init(PWM_Prescaler_t prescaler,
                             PWM_Postscaler_t postscaler,
                             uint8_t pr2)
{
    /* Set period register */
    PR2 = pr2;

    /* T2CON:
     *  bits<6:3> = TOUTPS<3:0> postscaler
     *  bit2      = TMR2ON
     *  bits<1:0> = T2CKPS<1:0> prescaler
     */
    T2CON = (uint8_t)(((uint8_t)postscaler << 3) | (1u << 2) | (uint8_t)prescaler);

    /* Clear Timer2 */
    TMR2 = 0x00u;
}

/*------------------------------------------------------------
 * PWM_Init
 *------------------------------------------------------------*/
void PWM_Init(const PWM_Config_t *cfg)
{
    /* Step 1: Set CCP pin as output */
    if (cfg->channel == PWM_CHANNEL_1) {
        TRISCbits.TRISC2 = 0;    /* RC2/CCP1 → output */
    } else {
        TRISCbits.TRISC1 = 0;    /* RC1/CCP2 → output */
    }

    /* Step 2: Set CCP to off before configuring Timer2 */
    if (cfg->channel == PWM_CHANNEL_1) {
        CCP1CON = 0x00u;
    } else {
        CCP2CON = 0x00u;
    }

    /* Step 3: Configure Timer2 */
    pwm_timer2_init(cfg->prescaler, cfg->postscaler, cfg->pr2Value);

    /* Step 4: Set initial duty cycle */
    PWM_SetDuty(cfg->channel, cfg->dutyCycle);

    /* Step 5: Enable CCP PWM mode */
    PWM_Start(cfg->channel);
}

/*------------------------------------------------------------
 * PWM_SetDuty (10-bit, 0–1023)
 * MSByte → CCPRxL
 * 2 LSBits → CCPxCON<5:4>
 *------------------------------------------------------------*/
void PWM_SetDuty(PWM_Channel_t channel, uint16_t dutyCycle)
{
    /* Clamp to 10 bits */
    if (dutyCycle > 1023u) dutyCycle = 1023u;

    uint8_t msb = (uint8_t)(dutyCycle >> 2);          /* bits<9:2> */
    uint8_t lsb = (uint8_t)(dutyCycle & 0x03u);       /* bits<1:0> */

    if (channel == PWM_CHANNEL_1) {
        CCPR1L = msb;
        CCP1CON = (uint8_t)((CCP1CON & 0xCFu) | (uint8_t)(lsb << 4) | CCP_PWM_MODE);
    } else {
        CCPR2L = msb;
        CCP2CON = (uint8_t)((CCP2CON & 0xCFu) | (uint8_t)(lsb << 4) | CCP_PWM_MODE);
    }
}

/*------------------------------------------------------------
 * PWM_SetDutyPercent
 *------------------------------------------------------------*/
void PWM_SetDutyPercent(PWM_Channel_t channel, uint8_t percent)
{
    uint16_t duty;
    if (percent >= 100u) {
        duty = 1023u;
    } else {
        duty = (uint16_t)((uint32_t)percent * 1023u / 100u);
    }
    PWM_SetDuty(channel, duty);
}

/*------------------------------------------------------------
 * PWM_SetPeriod
 *------------------------------------------------------------*/
void PWM_SetPeriod(uint8_t pr2Value)
{
    PR2 = pr2Value;
}

/*------------------------------------------------------------
 * PWM_Start
 *------------------------------------------------------------*/
void PWM_Start(PWM_Channel_t channel)
{
    if (channel == PWM_CHANNEL_1) {
        CCP1CON = (uint8_t)((CCP1CON & 0xF0u) | CCP_PWM_MODE);
    } else {
        CCP2CON = (uint8_t)((CCP2CON & 0xF0u) | CCP_PWM_MODE);
    }
}

/*------------------------------------------------------------
 * PWM_Stop
 *------------------------------------------------------------*/
void PWM_Stop(PWM_Channel_t channel)
{
    if (channel == PWM_CHANNEL_1) {
        CCP1CON = 0x00u;   /* Idle — CCP1 pin driven low */
    } else {
        CCP2CON = 0x00u;
    }
}

/*------------------------------------------------------------
 * PWM_CalcPR2
 * PR2 = (Fosc / (4 * freq * prescaler)) - 1
 *------------------------------------------------------------*/
uint8_t PWM_CalcPR2(uint32_t freqHz, uint32_t foscHz, uint8_t prescaler)
{
    uint32_t pr2 = (foscHz / (4u * freqHz * (uint32_t)prescaler)) - 1u;
    if (pr2 > 255u) pr2 = 255u;
    return (uint8_t)pr2;
}
