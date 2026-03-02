/*
* APPLICATION LAYER


*/
#include "../HAL/LED/LED_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../HAL/Switch/Switch_interface.h"
#include "../MCAL/EXT_INT/EXT_INT_interface.h"

void ToggleLED(void) {
    LED_Toggle(GPIO_PORTB, GPIO_PIN1);
}

void main() {
    LED_Init(GPIO_PORTB, GPIO_PIN1);

    EXT_INT0_Init();
    EXT_INT0_SetEdge(EXT_INT_FALLING_EDGE);
    EXT_INT0_SetCallback(ToggleLED); // Register the callback
    EXT_INT0_Enable();

    while(1) {
        // Main loop is empty; LED only toggles when button is pressed!
    }
}
