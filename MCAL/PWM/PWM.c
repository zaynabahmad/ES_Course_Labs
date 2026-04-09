#include "PWM_interface.h"
#include "PWM_private.h"
#include "PWM_config.h"

/* MCAL Dependencies */
#include "../GPIO/GPIO_interface.h"
#include "../TIMER_2/Timer2_interface.h" /* For prescaler macros */
#include "../../SERVICES/BIT_MATH.h"


/* Local variable to store the calculated period value */
static u8 u8_PR2_val;
static u8 u8_prescaler_val;

void PWM_Init(u8 channel)
{
    /* --- Step 1: Configure the PWM period using Timer2 --- */

    #if PWM_TMR2_PRESCALER == TIMER2_PRESCALER_1
        u8_prescaler_val = 1;
    #elif PWM_TMR2_PRESCALER == TIMER2_PRESCALER_4
        u8_prescaler_val = 4;
    #else
        u8_prescaler_val = 16;
    #endif

    /* Calculate PR2 value based on the formula: F_PWM = FOSC / ( (PR2 + 1) * 4 * TMR2_Prescaler ) */
    /* Rearranged: PR2 = (FOSC / (F_PWM * 4 * TMR2_Prescaler)) - 1 */
    u8_PR2_val = (u8)(((unsigned long)FOSC / ((unsigned long)PWM_FREQUENCY_HZ * 4 * u8_prescaler_val)) - 1);
    PR2 = u8_PR2_val;
    
    /* Set Timer2 prescaler */
    T2CON = (T2CON & 0b11111100) | PWM_TMR2_PRESCALER;

    /* --- Step 2: Configure the CCP module for PWM mode --- */
    if (channel == PWM_CHANNEL_1)
    {
        /* Set CCP1 pin (RC2) as an output */
        GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN2, GPIO_OUTPUT);
        
        /* Set CCP1 to PWM mode */
        CCP1CON |= (1 << CCPxM3_BIT) | (1 << CCPxM2_BIT);
    }
    else if (channel == PWM_CHANNEL_2)
    {
        /* Set CCP2 pin (RC1) as an output */
        GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN1, GPIO_OUTPUT);
        
        /* Set CCP2 to PWM mode */
        CCP2CON |= (1 << CCPxM3_BIT) | (1 << CCPxM2_BIT);
    }
}

void PWM_SetDutyCycle(u8 channel, u8 duty_cycle_percent)
{
    if (duty_cycle_percent <= 100)
    {
        /* Calculate the 10-bit duty cycle value */
        /* Formula: (Duty % / 100) * ( (PR2 + 1) * 4 ) */
        u16 duty_cycle_value = (((unsigned long)duty_cycle_percent * ((u8_PR2_val + 1) * 4)) / 100);

        if (channel == PWM_CHANNEL_1)
        {
            /* Write the 8 MSBs to CCPR1L */
            CCPR1L = (u8)(duty_cycle_value >> 2);
            
            /* Write the 2 LSBs to CCP1CON<5:4> */
            CCP1CON = (CCP1CON & 0b11001111) | ((duty_cycle_value & 0x03) << CCPxX_BIT);
        }
        else if (channel == PWM_CHANNEL_2)
        {
            /* Write the 8 MSBs to CCPR2L */
            CCPR2L = (u8)(duty_cycle_value >> 2);

            /* Write the 2 LSBs to CCP2CON<5:4> */
            CCP2CON = (CCP2CON & 0b11001111) | ((duty_cycle_value & 0x03) << CCPxX_BIT);
        }
    }
}

void PWM_Start(void)
{
    /* Start Timer2 */
    SET_BIT(T2CON, TMR2ON_BIT);
}

void PWM_Stop(void)
{
    /* Stop Timer2 */
    CLR_BIT(T2CON, TMR2ON_BIT);
}