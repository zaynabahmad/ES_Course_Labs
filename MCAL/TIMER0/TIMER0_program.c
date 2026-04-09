#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "TIMER0_private.h"
#include "TIMER0_interface.h"

void TIMER0_voidInit(void)
{
    CLR_BIT(OPTION_REG,5); // Timer mode
    SET_BIT(OPTION_REG,0); // Prescaler
}

void TIMER0_voidDelay(u8 time)
{
    while(time--)
    {
        TMR0 = 0;
        while(TMR0 < 255);
    }
}