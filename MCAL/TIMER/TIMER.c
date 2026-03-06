#include "../SERVICES/STD_TYPES.h"
#include "../SERVICES/BIT_MATH.h"
#include "TIMER_config.h"
#include "TIMER_private.h"

static volatile u32 count_ticks = 0;
static volatile u8 delayTime = 0;

void set_timerReg(void)
{
    TMR0 = 124;
}

void timer_intialize(void)
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

u32 time_elapsed(void)
{
    return (u32)(count_ticks/31);
}

void reset_timerTicks(void)
{
    count_ticks = 0;
    set_timerReg();
}

bool check_delay(void)
{
    return delayTime > time_elapsed();
}



void increment_timerTicks(void)
{
    count_ticks++;
}

u32 get_timerTicks(void)
{
    return count_ticks;
}

void time_delay(u8 time)
{
    delayTime = time;
    reset_timerTicks();
    while(check_delay()){};
}


void adjusted_second_count(void)
{
    
    increment_timerTicks();
    if (get_timerTicks() == 0){}
    else if( !(get_timerTicks() % 30) )
    {
        set_timerReg();
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