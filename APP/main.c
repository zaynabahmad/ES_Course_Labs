#include "../HAL/LED/LED_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../HAL/LED/LED_interface.h"
#include "../MCAL/INT/INT_interface.h"
#include "../HAL/SWITCH/SWITCH_interface.h"
#include "STD_TYPES.h"
#include "UTIL.h"




// INTERUPT TASK
//Pass this function to my callback function so it can be called during ISR 

void toggle_LED(void)
{
    LED_Toggle(GPIO_PORTC,GPIO_PIN0);
}

void setup()
{
    //Intializes used port pins intial states
    GPIO_Init();
    //Sets up pin direction interrupt
    EXT_INTO_Init();
    //Passes PTR to function into a static variable that can be accessed during ISR
    EXT_INTO_SetCallback(toggle_LED);
    //Enables interrupts 
    EXT_INTO_Enable(); 
    //Sets pin direction of required output PIN
    SWITCH_init();


}

void main()
{
    setup();
    while(1)
    {

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
