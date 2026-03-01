#include "LED.h"
#include "EXT_INT0.h"

#define LED_PIN 1

void Toggle_LED() {
    LED_Toggle(LED_PIN); // [cite: 17]
}

void main() {
    LED_Init(LED_PIN);   // Set RB1 as output 
    PORTB.F1 = 0;        // Initial state OFF

    EXT_INT0_Init();
    EXT_INT0_SetEdge(EXT_INT0_RISING_EDGE); // [cite: 19]
    EXT_INT0_SetCallback(Toggle_LED);
    EXT_INT0_Enable();

    while(1);
}