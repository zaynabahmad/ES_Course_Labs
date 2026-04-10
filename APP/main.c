#include "../HAL/LED/LED_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../HAL/SWITCH/SWITCH_interface.h"
#include "../SERVICES/BIT_MATH.h"
#include "../MCAL/EXT_INT/EXT_INT_interface.h"
#include "../MCAL/TIMER_0/TIMER_0_interface.h"


void delay(void)
{
    unsigned int i;
    for(i = 0; i < 50000; i++);
}

volatile u8 switchPressed = 0;

void SwitchCallback(void)
{
    switchPressed = 1;
}

void main()
{
    SWITCH_Init(GPIO_PIN0);
    EXT_INT_SetCallback(SwitchCallback);
    EXT_INT_Init();
    EXT_INT_Enable();


    while(1)
{
    if (switchPressed)
    {
        LED_Toggle(GPIO_PORTB, GPIO_PIN1);
        switchPressed = 0;
    }

    LED_On(GPIO_PORTB, GPIO_PIN0);
    delay();

    LED_Off(GPIO_PORTB, GPIO_PIN0);
    delay();
}
}