#include "../HAL/LED/LED_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/EXT_INT0/EXT_INT0_interface.h"
#include "../MCAL/TIMER0/TIMER0_interface.h"

// =================>Timer0 Driver<=================

volatile unsigned int tick_counter = 0;

void Interrupt() {

    if (TMR0IF_bit == 1) {
        TMR0IF_bit = 0; 
        TMR0 = 6;
        
        tick_counter++;
        
        if (tick_counter % 1000 == 0) {
            LED_Toggle(GPIO_PORTB, GPIO_PIN2);
        }
        
        if (tick_counter >= 2000) {
            LED_Toggle(GPIO_PORTB, GPIO_PIN1);
            
            tick_counter = 0; 
        }
    }
}

void main() {

    LED_Init(GPIO_PORTB, GPIO_PIN1);
    LED_Init(GPIO_PORTB, GPIO_PIN2);

    TIMER0_voidInit();
    while(1) {

    }
}