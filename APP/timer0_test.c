#include "../HAL/LED/LED_interface.h"
#include "../HAL/LED/LED_config.h"
#include "../MCAL/TIMER0/TIMER0_interface.h"
#include "../SERVICES/STD_TYPES.h"

#define APP_TIMER0_FULL_OVERFLOWS   30
#define APP_TIMER0_PARTIAL_PRELOAD  124

volatile u8 g_overflowCount = 0;
volatile u8 g_led1Seconds = 0;
volatile u8 g_led2Seconds = 0;

void APP_Timer0_Callback(void)
{
    if(g_overflowCount < APP_TIMER0_FULL_OVERFLOWS)
    {
        TIMER0_SetPreload(0);
        g_overflowCount++;
    }
    else
    {
        TIMER0_SetPreload(APP_TIMER0_PARTIAL_PRELOAD);
        g_overflowCount = 0;

        g_led2Seconds++;
        g_led1Seconds++;

        if(g_led2Seconds >= 1)
        {
            LED_Toggle(LED2_PORT, LED2_PIN);
            g_led2Seconds = 0;
        }

        if(g_led1Seconds >= 2)
        {
            LED_Toggle(LED1_PORT, LED1_PIN);
            g_led1Seconds = 0;
        }
    }
}

void APP_TIMER0_Test(void)
{
    LED_Init(LED1_PORT, LED1_PIN);
    LED_Init(LED2_PORT, LED2_PIN);

    LED_Off(LED1_PORT, LED1_PIN);
    LED_Off(LED2_PORT, LED2_PIN);

    TIMER0_SetCallback(APP_Timer0_Callback);
    TIMER0_Init();
    TIMER0_EnableInterrupt();

    while(1)
    {
    }
}