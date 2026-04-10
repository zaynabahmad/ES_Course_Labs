// Purpose: Tests interrupt by counting button presses
// Connect button to RB0 - it will respond even if main is in a delay

#include "exti.h"
#include "gpio.h"

volatile uint8 button_press_count = 0;  // volatile = can change in interrupt

void ButtonPressed(void) {
    // This runs IMMEDIATELY when button is pressed
    button_press_count++;

    // Blink LED on RB1 to show button was detected
    GPIO_TogglePin(PORTB_ID, PIN1);
}

void EXTI_Test(void) {
    // Setup LED on RB1
    GPIO_SetPinDirection(PORTB_ID, PIN1, OUTPUT);
    GPIO_WritePin(PORTB_ID, PIN1, LOW);

    // Setup interrupt
    EXTI_SetCallback(ButtonPressed);      // What to do when button pressed
    EXTI_Init(EXTI_FALLING_EDGE);         // Trigger when button pressed (5V->0V)
    EXTI_Enable();                         // Turn on interrupts

    while(1) {
        // Main loop can do anything - interrupts still work!
        // Just wait here, button will still be detected
        __delay_ms(100);
    }
}