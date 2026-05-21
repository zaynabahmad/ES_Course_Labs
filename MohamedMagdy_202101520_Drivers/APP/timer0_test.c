#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/TIMER_0/TIMER_0_Interface.h"
#include "timer0_test.h"

#define TIMER_LED_PORT  GPIO_PORTD
#define TIMER_LED_PIN   GPIO_PIN3

static u8 timer_led_state = GPIO_LOW;

static void Timer0_Overflow_Callback(void)
{
    if(timer_led_state == GPIO_LOW)
    {
        timer_led_state = GPIO_HIGH;
    }
    else
    {
        timer_led_state = GPIO_LOW;
    }

    GPIO_SetPinValue(TIMER_LED_PORT, TIMER_LED_PIN, timer_led_state);
}

void TIMER0_Test(void)
{
    GPIO_SetPinDirection(TIMER_LED_PORT, TIMER_LED_PIN, GPIO_OUTPUT);
    GPIO_SetPinValue(TIMER_LED_PORT, TIMER_LED_PIN, GPIO_LOW);

    TIMER0_Init();

    TIMER0_SetCallback(Timer0_Overflow_Callback);

    TIMER0_Enable();
}
