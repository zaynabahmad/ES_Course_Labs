#include "app_tests.h"

#include "../MCAL/TIMER_0/TIMER_0_Interface.h"

static void APP_Timer0Callback(void)
{
}

void APP_Test_TIMER0(void)
{
    TIMER0_Init();
    TIMER0_SetPreload(0U);
    TIMER0_SetCallback(APP_Timer0Callback);
    TIMER0_EnableInterrupt();
    TIMER0_Start();
}
