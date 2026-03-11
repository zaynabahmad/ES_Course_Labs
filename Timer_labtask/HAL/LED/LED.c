#include "LED.h"

// TRISB and PORTB registers
extern volatile unsigned char TRISB;
extern volatile unsigned char PORTB;

void LED_Init(Led_t *led) {
    // Set pin as output
    TRISB &= ~(1 << led->pin);
    // Start with LED off
    PORTB &= ~(1 << led->pin);
}

void LED_Toggle(Led_t *led) {
    PORTB ^= (1 << led->pin);
}