/*
* APPLICATION LAYER


*/
#include "../HAL/LED/LED_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../HAL/PUSH_BUTTON/PUSH_BUTTON_INTERFACE.h"


void fast_blinking(){
     LED_On(GPIO_PORTB, GPIO_PIN0);
    LED_On(GPIO_PORTB, GPIO_PIN1);
    Delay_ms(200);
    LED_Off(GPIO_PORTB, GPIO_PIN0);
    LED_Off(GPIO_PORTB, GPIO_PIN1);
    Delay_ms(200);
}

void slow_blinking(){
LED_On(GPIO_PORTB, GPIO_PIN0);
    LED_On(GPIO_PORTB, GPIO_PIN1);
    Delay_ms(500);
    LED_Off(GPIO_PORTB, GPIO_PIN0);
    LED_Off(GPIO_PORTB, GPIO_PIN1);
    Delay_ms(500);
}

void main()
{
    LED_Init(GPIO_PORTB, GPIO_PIN0);
    LED_Init(GPIO_PORTB, GPIO_PIN1);
    PUSH_BUTTON_Init(GPIO_PORTB, GPIO_PIN2);
    PUSH_BUTTON_Init(GPIO_PORTB, GPIO_PIN3);
    
    while(1)
    {
     if (BUTTON_Read(GPIO_PORTB, GPIO_PIN2) == 1) {
         fast_blinking();
     }
     else if (BUTTON_Read(GPIO_PORTB , GPIO_PIN3) == 1) {
           slow_blinking();
     }
     else {
         LED_Off(GPIO_PORTB, GPIO_PIN0);
         LED_Off(GPIO_PORTB, GPIO_PIN1);
     }
    }
}