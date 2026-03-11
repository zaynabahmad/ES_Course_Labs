/*
* APPLICATION LAYER
*/

#include "../MCAL/TIMER0/timer0_interface.h"
#include "../HAL/LED/LED_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"

volatile u8 count1 = 0;
volatile u8 count2 = 0;

void App_Timer_Callback(void)
{
    count1++;
    count2++;
    // Toggle LED1 every 1 second (since Timer0 overflows every ~32ms, we check for 31 overflows)
    if(count1 >= 31)
    {
        count1 = 0;
        LED_Toggle(GPIO_PORTA, GPIO_PIN0);  // LED1 every 1 second
    }
    // Toggle LED2 every 2 seconds (since Timer0 overflows every ~32ms, we check for 61 overflows)
    if(count2 >= 61)
    {
        count2 = 0;
        LED_Toggle(GPIO_PORTA, GPIO_PIN1);  // LED2 every 2 seconds
    }
}

void main(void)
{
    LED_Init(GPIO_PORTA, GPIO_PIN0); // Initialize LED1
    LED_Init(GPIO_PORTA, GPIO_PIN1); // Initialize LED2

    TIMER0_Init(); // Initialize Timer0
    TIMER0_SetCallback(App_Timer_Callback); // Set the callback function for Timer0 interrupts
    TIMER0_EnableInterrupt(); // Enable Timer0 interrupts

    while(1) { }
}