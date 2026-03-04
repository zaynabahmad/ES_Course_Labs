#include "../SERVICES/STD_TYPES.h"
#include "../HAL/LED/LED_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/EXT_INT/EXT_INT_interface.h"

void delay_fast(void) {
    u32 i;
    for (i = 0; i < 35000; i++);
}

void delay_slow(void) {
    u32 i;
    for (i = 0; i < 85000; i++);
}

void APP_InterruptAction(void) {
    LED_Toggle(GPIO_PORTD, GPIO_PIN2);
}

void main()
{
  
    LED_Init(GPIO_PORTD, GPIO_PIN0);
    LED_Init(GPIO_PORTD, GPIO_PIN1);
    LED_Init(GPIO_PORTD, GPIO_PIN2);

    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN0, GPIO_INPUT);
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN1, GPIO_INPUT);

    /* Initialize External Interrupt and Register Callback */
    EXT_INT0_Init();
    EXT_INT0_SetCallback(APP_InterruptAction);
    EXT_INT0_Enable();

    while (1)
    {
        /* Task 1 - LED Sequences Controlled by Switches */

        if (GPIO_GetPinValue(GPIO_PORTC, GPIO_PIN0) == GPIO_HIGH)
        {
            /* Short sequence (0.2s ON / 0.2s OFF) */
            LED_On(GPIO_PORTD, GPIO_PIN0);
            LED_On(GPIO_PORTD, GPIO_PIN1);
            delay_fast();
            LED_Off(GPIO_PORTD, GPIO_PIN0);
            LED_Off(GPIO_PORTD, GPIO_PIN1);
            delay_fast();
        }
        else if (GPIO_GetPinValue(GPIO_PORTC, GPIO_PIN1) == GPIO_HIGH)
        {
            /* Long sequence (0.5s ON / 0.5s OFF) */
            LED_On(GPIO_PORTD, GPIO_PIN0);
            LED_On(GPIO_PORTD, GPIO_PIN1);
            delay_slow();
            LED_Off(GPIO_PORTD, GPIO_PIN0);
            LED_Off(GPIO_PORTD, GPIO_PIN1);
            delay_slow();
        }
        else
        {
            /* Turn off LEDs if no switch is pressed */
            LED_Off(GPIO_PORTD, GPIO_PIN0);
            LED_Off(GPIO_PORTD, GPIO_PIN1);
        }
    }
}