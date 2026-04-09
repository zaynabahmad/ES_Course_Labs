/*
 * pwm.h
 * MCAL - PWM Driver Interface for PIC16F877A (CCP1 on RC2, CCP2 on RC1)
 */

#ifndef PWM_H
#define PWM_H

typedef unsigned char  u8;
typedef unsigned int   u16;

/* =====================================================
 * Type Definitions
 * ===================================================== */

typedef enum {
    PWM_CHANNEL_1 = 1,   /* CCP1 on RC2 */
    PWM_CHANNEL_2 = 2    /* CCP2 on RC1 */
} PWM_Channel_t;

typedef enum {
    PWM_PRESCALER_1  = 0,
    PWM_PRESCALER_4  = 1,
    PWM_PRESCALER_16 = 2
} PWM_Prescaler_t;

/* =====================================================
 * Function Prototypes
 * ===================================================== */

/**
 * @brief  Initialize PWM on selected channel
 * @param  ch         : PWM_CHANNEL_1 or PWM_CHANNEL_2
 * @param  prescaler  : Timer2 prescaler
 * @param  period     : PR2 value (determines PWM frequency)
 *         Fpwm = Fosc / (4 * prescaler * (PR2+1))
 *         For 4MHz, prescaler=4, PR2=124: Fpwm = 2kHz
 */
void PWM_Init(PWM_Channel_t ch, PWM_Prescaler_t prescaler, u8 period);

/**
 * @brief  Set duty cycle (0-1023 for 10-bit resolution)
 * @param  ch        : PWM channel
 * @param  dutyCycle : 0 (0%) to 1023 (100%)
 */
void PWM_SetDuty(PWM_Channel_t ch, u16 dutyCycle);

/**
 * @brief  Set duty cycle as percentage 0-100
 */
void PWM_SetDutyPercent(PWM_Channel_t ch, u8 percent);

/**
 * @brief  Stop PWM output (set pin low)
 */
void PWM_Stop(PWM_Channel_t ch);

/**
 * @brief  Start (resume) PWM output
 */
void PWM_Start(PWM_Channel_t ch);

#endif /* PWM_H */
