// ES_Drivers/APP/extint_test.c
#include "ISR_Actions.h"
#include "../HAL/LED/LED_interface.h"
#include "../MCAL/EXT_INT0/EXT_INT0_interface.h"
#include "extint_test.h"

void App_ToggleLed(void)
{
    LED_Toggle(GPIO_PORTB, GPIO_PIN1);  // safe: called from main context only
}

void EXTINT_Test(void)
{
    LED_Init(GPIO_PORTB, GPIO_PIN1);
    EXT_INT_Init(rising_edge);
    EXT_INT_Enable();

    while(1)
    {
        if (g_flag_extint)
        {
            g_flag_extint = 0;          // clear before acting
            App_ToggleLed();            // main context — no reentrancy
        }
    }
}