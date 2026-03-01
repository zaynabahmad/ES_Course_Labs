#include "LED.h"

void LED_Init(uint8 pin) {
    // MikroC uses TRISB bits directly or masking
    TRISB &= ~(1 << pin); // [cite: 2, 3]
}

void LED_Toggle(uint8 pin) {
    PORTB ^= (1 << pin); // [cite: 17]
}