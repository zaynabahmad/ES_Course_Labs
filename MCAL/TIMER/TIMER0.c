#include "TIMER0_interface.h"
#include "../GPIO/GPIO_private.h"

static void (*TMR0_Callback)(void) = 0;

void Timer0_initialize(void)
{

    OPTION_REG &= 0xF8;
    
    OPTION_REG |= 0x07;

    CLR_BIT(OPTION_REG, 3);


    CLR_BIT(OPTION_REG, 5);

    TMR0 = 0;

    CLR_BIT(INTCON, 2);
}

void Timer0_Enable(void)
{
    SET_BIT(INTCON, 5);
    SET_BIT(INTCON, 7);
}

void Timer0_Disable(void)
{
    CLR_BIT(INTCON, 5);
}

void TMR0_SetCallback(void (*ptr)(void))
{
    TMR0_Callback = ptr;
}

void Timer0_Reset(void)
{
    TMR0 = 0;
    CLR_BIT(INTCON, 2);
}

void Timer0_Set(u8 value)
{
    TMR0 = value;
    
}

u8 Timer0_get_flag(void)
{
    return GET_BIT(INTCON, 2);
}

void Timer0_set_flag(void)
{
    SET_BIT(INTCON, 2);
}

void Timer0_clr_flag(void)
{
    CLR_BIT(INTCON, 2);
}


void interrupt()
{
    if ((GET_BIT(INTCON, 2) == 1) )
    {
        CLR_BIT(INTCON, 2);

        if (TMR0_Callback)
        {
            TMR0_Callback();
        }
    }
}