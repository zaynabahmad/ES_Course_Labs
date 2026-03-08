#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GENERAL_DEFS.h"
#include "PWM_interface.h"
#include "PWM_private.h"
#include "PWM_config.h"
#include "../MCAL/TIMER/TIMER2/TIMER2_interface.h"

void PWM_inti(void)
{
    SET_BIT(CCP1CON, CCP1M3);
    SET_BIT(CCP1CON, CCP1M2);
    CLR_BIT(CCP1CON, CCP1M1);
    CLR_BIT(CCP1CON, CCP1M0);

    timer_2_intialize();
}

//Duty Cycle is set by using the desired duty cycle the user wants to get the requried PR2 value that needs to be set 
void PWM_setDutyCycle(u8 desired_dutyCycle)
{
    //Just a check to help debugging
    if (desired_dutyCycle > 100)
    {
        desired_dutyCycle = 100;
    }

    //timeForTick = (4*get_preScaler())/FOSC;
    //timePeriodTotal = (get_PR2() + 1) * timeForTick;

    //Your duty cycle is essentially just trying to get what percentage of the total time period you want your signal to be high
    //PWM duty cycle = (CCPR1L:CCP1CON<5:4>) • TOSC • (TMR2 prescale value)
    //By dividing the this equation for the duty cycle by the total timer period you get the following expression for the 10-bit register
    u32 totalRegisterVal = ((u32)desired_dutyCycle * 4 * (get_PR2() + 1)) / 100;

    CCPR1L = (u8)(totalRegisterVal >> 2);

    if( GET_BIT(totalRegisterVal, 0) ) 
    {
        SET_BIT(CCP1CON, CCP1Y);
    }
    else
    {
        CLR_BIT(CCP1CON, CCP1Y);
    }

    if (GET_BIT(totalRegisterVal, 1))
    {
        SET_BIT(CCP1CON, CCP1X);
    }
    else
    {
        CLR_BIT(CCP1CON, CCP1X);
    }
    
}

//Period is set by using the desired period the user wants to get the requried PR2 value that needs to be set 
void PWM_setFrequency(u32 desired_frequency)
{
    u32 denominator = 4 * desired_frequency * get_preScaler();
    u32 pr2_value = (FOSC / denominator) - 1;
    

    //This check is meant to make the behavior a bit defined for testing 
    //if values are always greater than the size of the register itll always give the maximum 
    //So will hopefully be able to pin point issue if it occurs during testing
    if (pr2_value <= 255)
    {
        set_period_timer_2_Reg((u8)pr2_value);
    }
    else
    {
        set_period_timer_2_Reg(255);
    }
}
