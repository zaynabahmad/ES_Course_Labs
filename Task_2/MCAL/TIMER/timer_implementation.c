#include "../../SERVICES/std_types.h"
#include "../../SERVICES/bit_math.h"

#include "timer_interface.h"

/* Keep only one callback pointer */
static void (*timer_callback)(void) = 0;

void TIMER0_ISR_Handler(void)
{
    /* Check and call the correct pointer */
    if(timer_callback != 0)
    {
        timer_callback();
    }
}

void TIMER0_Init(void)
{
    /* Timer mode */
    CLR_BIT(OPTION_REG,5);

    /* Prescaler assigned to Timer0 */
    CLR_BIT(OPTION_REG,3);

    /* Prescaler = 1:256 */
    SET_BIT(OPTION_REG,2);
    SET_BIT(OPTION_REG,1);
    SET_BIT(OPTION_REG,0);

    /* Enable Timer0 interrupt */
    SET_BIT(INTCON,5);

    /* Enable global interrupts */
    SET_BIT(INTCON,7);
}

void TIMER0_SetPreload(u8 preload)
{
    TMR0 = preload;
}

void TIMER0_SetCallback(void (*ptr)(void))
{
    /* Assign the address to the correct pointer */
    timer_callback = ptr;
}