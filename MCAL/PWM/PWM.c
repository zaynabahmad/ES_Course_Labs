#include "PWM_interface.h"
#include "PWM_private.h"
#include "PWM_config.h"
#include "../../SERVICES/Bit_Math.h"

void PWM_Init(u8 pwm_mode, u16 frequency) {
    u8 prescaler = PWM_TIMER2_PRESCALE;
    u16 pr2_value;
    
    /* Calculate PR2 value for desired frequency */
    /* Frequency = Fosc / (4 * (PR2+1) * Prescale) */
    pr2_value = (OSC_FREQ / (4 * frequency * prescaler)) - 1;
    
    /* Configure Timer2 */
    T2CON = 0;  /* Clear T2CON */
    
    /* Set prescaler */
    if(prescaler == 1) {
        /* Prescale 1:1 - Set bits 1:0 = 00 */
        CLR_BIT(T2CON, T2CKPS0);
        CLR_BIT(T2CON, T2CKPS1);
    }
    else if(prescaler == 4) {
        /* Prescale 1:4 - Set bits 1:0 = 01 */
        SET_BIT(T2CON, T2CKPS0);
        CLR_BIT(T2CON, T2CKPS1);
    }
    else if(prescaler == 16) {
        /* Prescale 1:16 - Set bits 1:0 = 10 */
        CLR_BIT(T2CON, T2CKPS0);
        SET_BIT(T2CON, T2CKPS1);
    }
    
    /* Set PR2 for PWM period */
    PR2 = (u8)pr2_value;
    
    /* Configure CCP1/CCP2 based on mode */
    if(pwm_mode == PWM_MODE_CCP1) {
        CCP1CON = 0x0C;  /* PWM mode: 1100 */
        CCPR1L = 0;      /* Initialize with 0% duty cycle */
        /* Make RC2 output */
        CLR_BIT(TRISC, 2);
    }
    else if(pwm_mode == PWM_MODE_CCP2) {
        CCP2CON = 0x0C;  /* PWM mode: 1100 */
        CCPR2L = 0;      /* Initialize with 0% duty cycle */
        /* Make RC1 output */
        CLR_BIT(TRISC, 1);
    }
}

void PWM_SetDutyCycle(u8 pwm_mode, u8 duty_cycle) {
    /* Duty cycle register calculation */
    /* CCPR1L:CCP1CON<5:4> = (PR2+1) * 4 * (Duty/100) */
    u16 dc_value;
    
    if(duty_cycle > 100) duty_cycle = 100;
    
    dc_value = (((u16)(PR2 + 1) * 4 * duty_cycle) / 100);
    
    if(pwm_mode == PWM_MODE_CCP1) {
        CCPR1L = (u8)(dc_value >> 2);  /* Upper 8 bits */
        /* Lower 2 bits would go to CCP1CON<5:4> for 10-bit resolution */
    }
    else if(pwm_mode == PWM_MODE_CCP2) {
        CCPR2L = (u8)(dc_value >> 2);  /* Upper 8 bits */
        /* Lower 2 bits would go to CCP2CON<5:4> for 10-bit resolution */
    }
}

void PWM_Enable(u8 pwm_mode) {
    /* Timer2 is started by setting TMR2ON bit */
    SET_BIT(T2CON, TMR2ON);
}

void PWM_Disable(u8 pwm_mode) {
    /* Disable Timer2 */
    CLR_BIT(T2CON, TMR2ON);
}
