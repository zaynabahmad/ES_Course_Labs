#include "led.h"

void LED_Init(void) {
    TRISD.F0 = 0;  // RD0 as output
    PORTD.F0 = 0;  // Start OFF
}

void LED_Toggle(void) {
    PORTD.F0 = ~PORTD.F0;
}