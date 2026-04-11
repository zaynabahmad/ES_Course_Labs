#include "../MCAL/TIMER_0/TIMER_0_Interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"

void Toggle_LED(void)
{
    static u8 state = 0;

    state = !state;
    GPIO_WritePin(PORTB , PIN0 , state);
}

void main(void)
{

    GPIO_Init(PORTB , PIN0 , OUTPUT);

    TIMER0_SetCallback(Toggle_LED);
    TIMER0_Init();

    while(1)
    {

    }
}