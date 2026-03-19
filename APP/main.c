#include "../SERVICES/STD_TYPES.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/TIMER/Timer_interface.h"
#include "../HAL/LED/LED_interface.h"

/* Global Tick Counter */
volatile u32 u32_Millis = 0;

/* Callback function passed to the Timer driver */
void App_TimerTick(void) {
    u32_Millis++;
}

void main(void) {
    u32 Last_Time_LED1 = 0;
    u32 Last_Time_LED2 = 0;

    /* Initialize Hardware */
    LED_Init(GPIO_PORTB, GPIO_PIN1);
    LED_Init(GPIO_PORTB, GPIO_PIN2);

    /* Initialize Timer */
    TMR0_Init();
    TMR0_SetCallback(App_TimerTick);
    TMR0_Enable();

    while(1) {
        /*  1 Second */
        if ((u32_Millis - Last_Time_LED1) >= 1000) {
            LED_Toggle(GPIO_PORTB, GPIO_PIN1);
            Last_Time_LED1 = u32_Millis;
        }

        /*  2 Seconds */
        if ((u32_Millis - Last_Time_LED2) >= 2000) {
            LED_Toggle(GPIO_PORTB, GPIO_PIN2);
            Last_Time_LED2 = u32_Millis;
        }
    }
}