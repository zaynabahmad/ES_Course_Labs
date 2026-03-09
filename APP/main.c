#include "../HAL/LED/LED_interface.h"
#include "../HAL/Timer/Timer_Interface.h"
#include "../MCAL/Interrupt Manager/Interrupt_manager.h"

// Global variable to alternate LED toggling
volatile int even = 0;

// Callback function for Timer0 interrupt
void tmr_int_logic() {
    if (even == 0) {
        LED_Toggle(GPIO_PORTB, GPIO_PIN1);
        even = 1;
    } else {
        LED_Toggle(GPIO_PORTB, GPIO_PIN1);
        LED_Toggle(GPIO_PORTB, GPIO_PIN2);
        even = 0;
    }
}

int main(void) {
    // Initialize LEDs

    LED_Init(GPIO_PORTB, GPIO_PIN1);
    LED_Init(GPIO_PORTB, GPIO_PIN2);
    LED_Init(GPIO_PORTC,GPIO_PIN1);

    // Initialize Timer0 with prescaler 128
    Timer0_Init(128);

    // Set Timer0 delay to 1000ms and register callback
    Timer0_SetDelay(1000, tmr_int_logic);

    // Enable global interrupts after Timer0 is configured
    SET_BIT(INTCON, GIE_BIT);

    while (1) {
        
    }

    return 0;
}
