/*
* APPLICATION LAYER


*/
#include "../HAL/LED/LED_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../SERVICES/STD_TYPES.h"
#include "../MCAL/TMR0/TMR0_interface.h"

volatile u8 led1_count = 0;
volatile u8 led2_count = 0;

void HandleTimerOverflow(void) {
    led1_count++;
    led2_count++;

    // Toggle LED1 every ~1 second
    if (led1_count >= 50) {
        LED_Toggle(GPIO_PORTB, GPIO_PIN1);
        led1_count = 0;
    }

    // Toggle LED2 every ~2 seconds
    if (led2_count >= 100) {
        LED_Toggle(GPIO_PORTB, GPIO_PIN2);
        led2_count = 0;
    }
}





void main()
{

    LED_Init(GPIO_PORTB, GPIO_PIN1);
    LED_Init(GPIO_PORTB, GPIO_PIN2);
    
    TMR0_Init();

    
    TMR0_SetCallBack(HandleTimerOverflow);
    TMR0_SetPreloadValue(100);
    
    TMR0_Start();
    GIE_bit = 1;
    
    while(1){
    }
    
    


}