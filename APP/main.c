#include "../HAL/LED/LED_interface.h"
#include "../HAL/LED/LED_config.h"
#include "../MCAL/TIMER0/TIMER0_interface.h"
#include "../MCAL/EXT_INT/EXT_INT_interface.h"

static u8 seconds = 0;

void OneSecondCallback(void)
{
    seconds++;
    LED_Toggle(LED2_PORT, LED2_PIN);        /* RB2 toggles every 1 second  */

    if (seconds >= 2)
    {
        seconds = 0;
        LED_Toggle(LED1_PORT, LED1_PIN);    /* RB1 toggles every 2 seconds */
    }
}

/* Unified ISR dispatcher — the single interrupt() for this project.
   Each IRQHandler checks its own flag internally before acting,
   so both can be called on every interrupt safely.               */
void interrupt()
{
    TIMER0_IRQHandler();
    EXT_INT0_IRQHandler();
}

void main()
{
    LED_Init(LED1_PORT, LED1_PIN);          /* RB1 as output */
    LED_Init(LED2_PORT, LED2_PIN);          /* RB2 as output */

    TIMER0_Init();
    TIMER0_SetCallback(OneSecondCallback);

    while(1)
    {
        /* CPU idles here; all LED toggling is driven by Timer0 ISR */
    }
}
