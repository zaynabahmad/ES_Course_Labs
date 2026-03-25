/*#include "../HAL/LED/LED_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include  "../MCAL/Timer/TImer_interface.h "

#define TICKS_1_SEC  1
#define TICKS_2_SEC  2

volatile unsigned int led1_counter = 0;
volatile unsigned int led2_counter = 0;
void ToggleTask(){
    led1_counter++;
    led2_counter++;

    // Logic for LED2 (1 Second)
    if (led2_counter >= TICKS_1_SEC) {
        LED_Toggle(GPIO_PORTB, GPIO_PIN0); // Toggle LED2
        led2_counter = 0;      // Reset only this counter
    }

    // Logic for LED1 (2 Seconds)
    if (led1_counter >= TICKS_2_SEC) {
        LED_Toggle(GPIO_PORTB, GPIO_PIN1); // Toggle LED1
        led1_counter = 0;      // Reset only this counter
    }
}

void main()
{
    LED_Init(GPIO_PORTB, GPIO_PIN0);
    LED_Init(GPIO_PORTB, GPIO_PIN1);
    Timer0_Init();
    Timer0_SetCallback(ToggleTask);


    while(1)
    {


    }
}*/