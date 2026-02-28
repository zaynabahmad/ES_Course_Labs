/*
* APPLICATION LAYER


*/
#include "../HAL/LED/LED_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/EXT_INT/EXT_INT_interface.h"
#include "../HAL/Switch/Switch_interface.h"

// Inside main.c
void MyLogic() { LED_Toggle(GPIO_PORTC, GPIO_PIN0); }

void main()
{
    LED_Init(GPIO_PORTC, GPIO_PIN0);
    SWITCH_Init(GPIO_PORTB, GPIO_PIN0);
    EXT_INT_Init();
    EXT_INT_SetCallback(MyLogic);
    EXT_INT_Enable();
    while (1)
    {

    }
    
}