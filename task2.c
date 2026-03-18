#include "MCAL/GPIO/GPIO_interface.h"
#include "MCAL/TMR0/TMR0_interface.h"
#include "HAL/LED/LED_interface.h"
#include "SERVICES/STD_TYPES.h"

#define LED1_PORT   GPIO_PORTB
#define LED1_PIN    GPIO_PIN1    /* Toggles every 2000ms */

#define LED2_PORT   GPIO_PORTB
#define LED2_PIN    GPIO_PIN2    /* Toggles every 1000ms */

/* Tick counters (incremented every 1ms by Timer0 ISR) */

static volatile u8 led1_state = LED_OFF;
static volatile u8 led2_state = LED_OFF;



static volatile u16 tick_led1 = 0;
static volatile u16 tick_led2 = 0;

static void App_TimerTick(void)
{
    tick_led1++;
    tick_led2++;

    if (tick_led1 >= 60u)        /* ~2 seconds */
    {
        tick_led1 = 0;
        if (led1_state == LED_OFF) { LED_On(LED1_PORT,  LED1_PIN);  led1_state = LED_ON;  }
        else                       { LED_Off(LED1_PORT, LED1_PIN);  led1_state = LED_OFF; }
    }

    if (tick_led2 >= 30u)        /* ~1 second */
    {
        tick_led2 = 0;
        if (led2_state == LED_OFF) { LED_On(LED2_PORT,  LED2_PIN);  led2_state = LED_ON;  }
        else                       { LED_Off(LED2_PORT, LED2_PIN);  led2_state = LED_OFF; }
    }
}

void main(void)
{
    LED_Init(LED1_PORT, LED1_PIN);
    LED_Init(LED2_PORT, LED2_PIN);

    TMR0_Init();
    TMR0_SetCallback(App_TimerTick);
    TMR0_Enable();

    while(1)
    {

    }
}