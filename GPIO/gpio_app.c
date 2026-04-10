// Purpose: Tests if GPIO works (blinks LED when button pressed)
// Hardware: Connect LED to RB0, button to RB1

#include "gpio.h"

void GPIO_Test(void) {
    // Setup: RB0 = output (for LED), RB1 = input (for button)
    GPIO_SetPinDirection(PORTB_ID, PIN0, OUTPUT);
    GPIO_SetPinDirection(PORTB_ID, PIN1, INPUT);

    while(1) {
        // If button is pressed (reading = 1), turn LED on
        if(GPIO_ReadPin(PORTB_ID, PIN1) == 1) {
            GPIO_WritePin(PORTB_ID, PIN0, HIGH);
        }
        // Otherwise turn LED off
        else {
            GPIO_WritePin(PORTB_ID, PIN0, LOW);
        }

        Delay_ms(50);   // ? Capital D, no underscore  // Small delay to prevent button bouncing
    }
}