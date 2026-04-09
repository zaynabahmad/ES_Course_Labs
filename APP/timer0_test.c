#include "../MCAL/TIMER_0/TIMER_0_Interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "timer0_test.h"

static void timer0_handler(void)
{
    /* Toggle PORTD pin1 on each Timer0 overflow (~65 ms @ 4 MHz, PS=256) */
    u8 val = GPIO_GetPinValue(GPIO_PORTD, GPIO_PIN1);
    GPIO_SetPinValue(GPIO_PORTD, GPIO_PIN1, (val == GPIO_HIGH) ? GPIO_LOW : GPIO_HIGH);
}

void timer0_test_run(void)
{
    GPIO_SetPinDirection(GPIO_PORTD, GPIO_PIN1, GPIO_OUTPUT);
    GPIO_SetPinValue(GPIO_PORTD, GPIO_PIN1, GPIO_LOW);

    TIMER0_Init();
    TIMER0_SetPreload(0x00);
    TIMER0_SetCallback(timer0_handler);
    TIMER0_Start();
}
