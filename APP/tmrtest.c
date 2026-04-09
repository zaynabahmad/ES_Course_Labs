

#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/TIMER_0/TIMER_0_Interface.h"
#include "../HAL/LED/LED_interface.h"
#include "../SERVICES/STD_TYPES.h"

#define LED1_PORT   GPIO_PORTB
#define LED1_PIN    GPIO_PIN1

#define LED2_PORT   GPIO_PORTB
#define LED2_PIN    GPIO_PIN2

static volatile u8  led1_state = LED_OFF;
static volatile u8  led2_state = LED_OFF;
static volatile u16 tick_led1  = 0u;
static volatile u16 tick_led2  = 0u;

/*
 * Called every ~16 ms by Timer0 ISR (via TMR0_Callback).
 * Counts ticks and toggles LEDs at the correct intervals.
 * Keep this function SHORT — it runs inside an ISR.
 */
static void App_TimerTick(void)
{
    tick_led1++;
    tick_led2++;

    /* LED1: toggle every 125 ticks = ~2 seconds */
    if (tick_led1 >= 125u)
    {
        tick_led1 = 0u;
        if (led1_state == LED_OFF) { LED_On(LED1_PORT,  LED1_PIN);  led1_state = LED_ON;  }
        else                       { LED_Off(LED1_PORT, LED1_PIN);  led1_state = LED_OFF; }
    }

    /* LED2: toggle every 63 ticks = ~1 second */
    if (tick_led2 >= 63u)
    {
        tick_led2 = 0u;
        if (led2_state == LED_OFF) { LED_On(LED2_PORT,  LED2_PIN);  led2_state = LED_ON;  }
        else                       { LED_Off(LED2_PORT, LED2_PIN);  led2_state = LED_OFF; }
    }
}

int main(void)
{
    /* Init LEDs as outputs, start LOW */
    LED_Init(LED1_PORT, LED1_PIN);
    LED_Init(LED2_PORT, LED2_PIN);

    /* Register callback BEFORE enabling */
    TMR0_SetCallback(App_TimerTick);

    /* Configure Timer0: internal clock, prescaler 1:256, load preload */
    TMR0_Init();

    /* Enable Timer0 interrupt + GIE */
    TMR0_Enable();

    while (1)
    {
        /* Nothing here — all work done in App_TimerTick via ISR */
    }
    return 0;
}