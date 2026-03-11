/*
* APPLICATION LAYER


*/
#include "../HAL/LED/LED_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../HAL/SWITCH/SWITCH_interface.h"
#include "../SERVICES/BIT_MATH.h"

 #include "../HAL/BUTTON/BUTTON_interface.h"
#include "../MCAL/EXTI/EXTI_interface.h"
#include "../MCAL/TIMER/TIMER_interface.h"



void delay(void)
{
    unsigned int i;
    for(i = 0; i < 50000; i++);
}

void ButtonPressedCallback(void)
{

    LED_Toggle(GPIO_PORTB, GPIO_PIN1);
}
void ButtonPressedCallback2(void)
{

    LED_Toggle(GPIO_PORTB, GPIO_PIN2);
}


void Short_Sequence()
{
   LED_On(GPIO_PORTB, GPIO_PIN0);
   LED_On(GPIO_PORTB, GPIO_PIN1);
   Delay_ms(200);
   LED_Off(GPIO_PORTB, GPIO_PIN0);
   LED_Off(GPIO_PORTB, GPIO_PIN1);
   Delay_ms(200);
}

void Long_Sequence()
{
   LED_On(GPIO_PORTB, GPIO_PIN0);
   LED_On(GPIO_PORTB, GPIO_PIN1);
   Delay_ms(500);
   LED_Off(GPIO_PORTB, GPIO_PIN0);
   LED_Off(GPIO_PORTB, GPIO_PIN1);
   Delay_ms(500);
}



void main()
{    
    LED_Init(GPIO_PORTB, GPIO_PIN1);
    LED_Init(GPIO_PORTB, GPIO_PIN2);
    
    TIMER_INT();
    TIMER_SetCallback(ButtonPressedCallback);
    TIMER_SetCallback2(ButtonPressedCallback2);

    while(1)
    {
    }
}