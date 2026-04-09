#include "../MCAL/TIMER_0/TIMER_0_Interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"

/* LED state tracker */
static u8 led_state = 0;

/* Callback function */
void TIMER0_Callback_Function(void)
{
    if(led_state == 0)
    {
        GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN0, GPIO_HIGH);
        led_state = 1;
    }
    else
    {
        GPIO_SetPinValue(GPIO_PORTA, GPIO_PIN0, GPIO_LOW);
        led_state = 0;
    }
}

/* Test function */
void TIMER0_Test(void)
{
    /* Set LED pin as output */
    GPIO_SetPinDirection(GPIO_PORTA, GPIO_PIN0, GPIO_OUTPUT);

    /* Initialize Timer0 */
    TIMER0_Init();

    /* Register callback */
    TIMER0_SetCallback(TIMER0_Callback_Function);

    /* Enable Timer interrupt */
    TIMER0_Enable();

    while(1)
    {
        /*
         * Simulate interrupt manually
         */
        TIMER0_ISR();
    }
}