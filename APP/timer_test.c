#include "../SERVICES/STD_TYPES.h"
#include "../MCAL/TIMER_0/TIMER_0_Interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../HAL/LED/LED_interface.h"

#define TIMER_TEST_LED_PORT   GPIO_PORTA
#define TIMER_TEST_LED_PIN    GPIO_PIN2

static volatile u8 TIMER_LedToggleRequest;

static void TIMER_UserCallback(void)
{
    TIMER_LedToggleRequest = 1;
}

void TIMER_Test(void)
{
    u16 i;

    /* Initialize LED */
    LED_Init(TIMER_TEST_LED_PORT, TIMER_TEST_LED_PIN);

    /* Initialize Timer0 */
    TIMER0_Init();
    TIMER0_SetPreload(6);

    /* Blocking delay must run before T0 IRQ is enabled (ISR clears T0IF) */
    TIMER0_DelayMs(500);

    TIMER0_SetCallback(TIMER_UserCallback);
    TIMER0_EnableInterrupt();

    for(i = 0; i < 40000u; i++)
    {
        if(TIMER_LedToggleRequest)
        {
            TIMER_LedToggleRequest = 0;
            LED_Toggle(TIMER_TEST_LED_PORT, TIMER_TEST_LED_PIN);
        }
    }

    TIMER0_DisableInterrupt();
}
