#include "../SERVICES/STD_TYPES.h"
#include "../SERVICES/BIT_MATH.h"
#include "TIMER_config.h"
#include "TIMER_private.h"
#include "TIMER_interface.h"

static volatile u32 count_ticks = 0;
static volatile u8 delayTime = 0;

void set_timer_0_Reg(void)
{
    TMR0 = 124;
}

void set_timer_0_preScaller(u8 prescaler_value)
{
    //Yes i made AI write this switch case because i wouldnt write all these cases myself
    //Good use of AI !
    switch (prescaler_value)
    {
        case PRESCALER_1_2:
            // Prescaler 1:2 -> PS2:PS0 = 000
            CLR_BIT(OPTION_REG, PS2);
            CLR_BIT(OPTION_REG, PS1);
            CLR_BIT(OPTION_REG, PS0);
            break;
            
        case PRESCALER_1_4:
            // Prescaler 1:4 -> PS2:PS0 = 001
            CLR_BIT(OPTION_REG, PS2);
            CLR_BIT(OPTION_REG, PS1);
            SET_BIT(OPTION_REG, PS0);
            break;
            
        case PRESCALER_1_8:
            // Prescaler 1:8 -> PS2:PS0 = 010
            CLR_BIT(OPTION_REG, PS2);
            SET_BIT(OPTION_REG, PS1);
            CLR_BIT(OPTION_REG, PS0);
            break;
            
        case PRESCALER_1_16:
            // Prescaler 1:16 -> PS2:PS0 = 011
            CLR_BIT(OPTION_REG, PS2);
            SET_BIT(OPTION_REG, PS1);
            SET_BIT(OPTION_REG, PS0);
            break;
            
        case PRESCALER_1_32:
            // Prescaler 1:32 -> PS2:PS0 = 100
            SET_BIT(OPTION_REG, PS2);
            CLR_BIT(OPTION_REG, PS1);
            CLR_BIT(OPTION_REG, PS0);
            break;
            
        case PRESCALER_1_64:
            // Prescaler 1:64 -> PS2:PS0 = 101
            SET_BIT(OPTION_REG, PS2);
            CLR_BIT(OPTION_REG, PS1);
            SET_BIT(OPTION_REG, PS0);
            break;
            
        case PRESCALER_1_128:
            // Prescaler 1:128 -> PS2:PS0 = 110
            SET_BIT(OPTION_REG, PS2);
            SET_BIT(OPTION_REG, PS1);
            CLR_BIT(OPTION_REG, PS0);
            break;
            
        case PRESCALER_1_256:
            // Prescaler 1:256 -> PS2:PS0 = 111
            SET_BIT(OPTION_REG, PS2);
            SET_BIT(OPTION_REG, PS1);
            SET_BIT(OPTION_REG, PS0);
            break;
            
        default:
            // Default to maximum prescaler (1:256) for safety if an invalid value is passed
            SET_BIT(OPTION_REG, PS2);
            SET_BIT(OPTION_REG, PS1);
            SET_BIT(OPTION_REG, PS0);
            break;
    }
}

void timer_0_intialize(void)
{
    //Prescaller select 
    SET_BIT(OPTION_REG,PS0);
    SET_BIT(OPTION_REG,PS1);
    SET_BIT(OPTION_REG,PS2);

    //Prescaller assignment select
    CLR_BIT(OPTION_REG,PSA);

    //CLK internal or external select
    CLR_BIT(OPTION_REG,TOCS);
}

u32 time_timer_0_elapsed(void)
{
    return (u32)(count_ticks/31);
}

void reset_timer_0_Ticks(void)
{
    count_ticks = 0;
    set_timer_0_Reg();
}

bool check_delay(void)
{
    return delayTime > time_elapsed();
}

void increment_timer_0_Ticks(void)
{
    count_ticks++;
}

u32 get_timer_0_Ticks(void)
{
    return count_ticks;
}

void time_delay(u8 time)
{
    delayTime = time;
    reset_timer_0_Ticks();
    while(check_delay()){};
}

void adjusted_timer_0_second_count(void)
{
    
    increment_timer_0_Ticks();
    if (get_timer_0_Ticks() == 0){}
    else if( !(get_timer_0_Ticks() % 30) )
    {
        set_timer_0_Reg();
    }

}






/*
u32 times_timer_elapsed(u8 time)
{
    u32 time_micro = ((u32)time)*1000000UL;

    u32 time_elapsed = count_ticks * INTERNALCLK_TICK_PER;

    return time_elapsed / time_micro;
}
*/