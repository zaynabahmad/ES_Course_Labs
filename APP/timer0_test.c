#include "app_tests.h"
#include "../HAL/LED/LED_interface.h"
#include "../MCAL/TIMER_0/TIMER_0_Interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"

static volatile u8 APP_TIMER0_Pending = 0;
static TIMER0_ConfigType APP_TIMER0_Config = {TIMER0_TIMER_MODE, TIMER0_LOW_TO_HIGH_EDGE, TIMER0_PRESCALER_TO_TIMER0, 7, 6, 1};

static void APP_TIMER0_Handler(void)
{
    APP_TIMER0_Pending = 1;
}

void APP_TIMER0_Test(void)
{
    LED_Init(GPIO_PORTC, GPIO_PIN1);
    TIMER0_Init(&APP_TIMER0_Config);
    TIMER0_SetCallback(APP_TIMER0_Handler);
    TIMER0_Start();
}

void APP_TIMER0_Task(void)
{
    if (APP_TIMER0_Pending != 0)
    {
        APP_TIMER0_Pending = 0;
        LED_Toggle(GPIO_PORTC, GPIO_PIN1);
    }
}
