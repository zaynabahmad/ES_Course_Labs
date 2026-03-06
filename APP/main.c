#include "../HAL/LED/LED_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/INT/INT_interface.h"
#include "../HAL/SWITCH/SWITCH_interface.h"
#include "../MCAL/TIMER/TIMER_interface.h"
#include "STD_TYPES.h"
#include "UTIL.h"


//Week 2 Timer_based blinking LED 

void toggle_LED_1(void)
{
    LED_Toggle(GPIO_PORTB,GPIO_PIN0);
    time_delay(1);
    LED_Toggle(GPIO_PORTB,GPIO_PIN0);
    time_delay(1);
}
void toggle_LED_2(void)
{
    LED_Toggle(GPIO_PORTB,GPIO_PIN0);
    time_delay(2);
    LED_Toggle(GPIO_PORTB,GPIO_PIN0);
    time_delay(2);
}

void setup()
{
    //Intializes used port pins intial states
    GPIO_Init();
    //Enables interrupts 
    TIMR_INTR_ENABLE();
    //Initalize timer
    timer_intialize(); 
}

void main()
{
    setup();
    while(1)
    {
        toggle_LED_1();
        toggle_LED_2();

    }
}



//LED TASK 
/*
void setup()
{
    GPIO_Init();

    //Setting pin to be output for LED
    LED_Init(GPIO_PORTC,GPIO_PIN0);
    SWITCH_init();
    

}

void main()
{
    setup();
    while(1)
    {
        if(SWITCH_CHECK(SWTICH_SLOW)) {BLINKSLOW();}
        else if(SWITCH_CHECK(SWITCH_FAST)) {BLINKFAST();}
    }
}
*/
