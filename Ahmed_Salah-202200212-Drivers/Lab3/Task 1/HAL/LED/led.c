#include "led.h"

void LED_Init(void) {
    TRISB.F1 = 0;  // LED1 Output
    TRISB.F2 = 0;  // LED2 Output
    PORTB.F1 = 0;
    PORTB.F2 = 0;
}

void LED1_Toggle(void) { PORTB.F1 = ~PORTB.F1; }
void LED2_Toggle(void) { PORTB.F2 = ~PORTB.F2; }