#include "../MCAL/TIMER_0/TIMER_0_Interface.h"

void Timer0_Test(void)
{
    /* Initialize Timer0 with 1:256 prescaler */
    TIMER0_Init(7);

    /* Set preload value for custom timing */
    TIMER0_SetPreload(0);

    /* Test 1: Delay function (polling-based) */
    TIMER0_DelayMs(1000);  /* 1 second delay */

    /* Test 2: Enable interrupt-driven overflow */
    TIMER0_EnableOverflowInterrupt();

    /* Set a callback function for interrupts */
    TIMER0_SetCallback(NULL_PTR);

    /* Test 3: Disable interrupt */
    TIMER0_DisableOverflowInterrupt();
}
