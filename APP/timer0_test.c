#include "timer_test.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/TIMER0/TIMER0_interface.h"
#include "timer_test.h"


void TIMER_Test(void)
{
    GPIO_SetPinDirection(PORTB, PIN0, OUTPUT);

    TIMER0_Init();
    TIMER0_Start();

    while(1)
    {

    }
}