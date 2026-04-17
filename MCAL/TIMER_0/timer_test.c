#include "../MCAL/TIMER_0/TIMER_0_Interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"

static void Timer0_OverflowHandler(void)
{
    /* Toggle LED on every overflow */
    static u8 ledState = GPIO_LOW;
    ledState = (ledState == GPIO_HIGH) ? GPIO_LOW : GPIO_HIGH;
    GPIO_SetPinValue(GPIO_PORTD, GPIO_PIN1, ledState);
}

void TIMER0_Test(void)
{
    GPIO_SetPinDirection(GPIO_PORTD, GPIO_PIN1, GPIO_OUTPUT);
    TIMER0_Init();
    TIMER0_SetCallback(Timer0_OverflowHandler);
    TIMER0_Enable();
}
