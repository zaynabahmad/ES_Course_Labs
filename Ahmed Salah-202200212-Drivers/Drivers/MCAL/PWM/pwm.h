/**
 * @file    pwm.h
 * @brief   PIC16F877 PWM Driver Header (CCP1 & CCP2 modules)
 * @details Uses Timer2 as the PWM timebase.
 *
 * Key Registers (DS30292C):
 *   CCP1CON (0x17) — bits<5:4> DC1B1:DC1B0 (LSBs of duty), bits<3:0> CCP1M
 *   CCP2CON (0x1D) — same layout for CCP2
 *   CCPR1L  (0x15) — bits<7:0> of 10-bit duty cycle (MSBs)
 *   CCPR2L  (0x1B) — bits<7:0> of 10-bit duty cycle (MSBs)
 *   PR2     (0x92) — PWM period register
 *   T2CON   (0x12) — TMR2 on/off, postscaler, prescaler
 *   PIR1    (0x0C) — TMR2IF
 *   PIE1    (0x8C) — TMR2IE
 *
 * PWM Period  = (PR2 + 1) * 4 * Tosc * TMR2_Prescaler
 * PWM Duty DC = (CCPRXL:DCXB<1:0>) * Tosc * TMR2_Prescaler
 *
 * At Fosc=4MHz, PR2=249, Prescaler=1 → Period=1kHz, Resolution=10bit
 *
 * Pin mapping:
 *   CCP1 → RC2 (pin 17 on 40-pin package)
 *   CCP2 → RC1 (pin 16 on 40-pin package)
 */

#ifndef PWM_H
#define PWM_H

#include <pic16f877.h>
#include <stdint.h>

/*============================================================
 * PWM Channel
 *============================================================*/
typedef enum {
    PWM_CHANNEL_1 = 1,   /* CCP1 / RC2 */
    PWM_CHANNEL_2 = 2    /* CCP2 / RC1 */
} PWM_Channel_t;

/*============================================================
 * Timer2 Prescaler
 *============================================================*/
typedef enum {
    PWM_PRESCALER_1  = 0x00,
    PWM_PRESCALER_4  = 0x01,
    PWM_PRESCALER_16 = 0x02
} PWM_Prescaler_t;

/*============================================================
 * Timer2 Postscaler (1:1 to 1:16 encoded as 0–15)
 *============================================================*/
typedef enum {
    PWM_POSTSCALER_1  = 0,
    PWM_POSTSCALER_2  = 1,
    PWM_POSTSCALER_3  = 2,
    PWM_POSTSCALER_4  = 3,
    PWM_POSTSCALER_5  = 4,
    PWM_POSTSCALER_6  = 5,
    PWM_POSTSCALER_7  = 6,
    PWM_POSTSCALER_8  = 7,
    PWM_POSTSCALER_9  = 8,
    PWM_POSTSCALER_10 = 9,
    PWM_POSTSCALER_11 = 10,
    PWM_POSTSCALER_12 = 11,
    PWM_POSTSCALER_13 = 12,
    PWM_POSTSCALER_14 = 13,
    PWM_POSTSCALER_15 = 14,
    PWM_POSTSCALER_16 = 15
} PWM_Postscaler_t;

/*============================================================
 * Configuration Structure
 *============================================================*/
typedef struct {
    PWM_Channel_t    channel;       /* CCP1 or CCP2              */
    uint8_t          pr2Value;      /* PR2 period register value  */
    PWM_Prescaler_t  prescaler;     /* Timer2 prescaler           */
    PWM_Postscaler_t postscaler;    /* Timer2 postscaler          */
    uint16_t         dutyCycle;     /* 0–1023 (10-bit resolution) */
} PWM_Config_t;

/*============================================================
 * API
 *============================================================*/

/**
 * @brief  Initialize PWM for one or both channels
 * @note   Timer2 is shared; configure Timer2 once (first call sets it)
 * @param  cfg  Pointer to PWM_Config_t
 */
void PWM_Init(const PWM_Config_t *cfg);

/**
 * @brief  Set duty cycle at runtime (0–1023)
 * @param  channel    PWM_CHANNEL_1 or PWM_CHANNEL_2
 * @param  dutyCycle  10-bit value (0 = 0%, 1023 = ~100%)
 */
void PWM_SetDuty(PWM_Channel_t channel, uint16_t dutyCycle);

/**
 * @brief  Set duty cycle as a percentage (0–100)
 * @param  channel  PWM_CHANNEL_1 or PWM_CHANNEL_2
 * @param  percent  0–100
 */
void PWM_SetDutyPercent(PWM_Channel_t channel, uint8_t percent);

/**
 * @brief  Change PR2 period register and update Timer2
 * @param  pr2Value  New PR2 value
 */
void PWM_SetPeriod(uint8_t pr2Value);

/** @brief  Start PWM output on channel (enable CCP mode) */
void PWM_Start(PWM_Channel_t channel);

/** @brief  Stop PWM output on channel (set CCP to idle) */
void PWM_Stop(PWM_Channel_t channel);

/**
 * @brief  Compute PR2 for a desired frequency
 * @param  freqHz     Desired PWM frequency in Hz
 * @param  foscHz     Crystal frequency in Hz (e.g., 4000000)
 * @param  prescaler  Timer2 prescaler value (1, 4, or 16)
 * @return PR2 register value
 */
uint8_t PWM_CalcPR2(uint32_t freqHz, uint32_t foscHz, uint8_t prescaler);

#endif /* PWM_H */
