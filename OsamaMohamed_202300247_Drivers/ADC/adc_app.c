
#include "../pic_config.h"
#include "adc.h"
#include "../GPIO/gpio.h"

void main() {
    ADCON1 = 0x80;     // Right-justified, all analog
    TRISD  = 0x00;     // PORTD output
    TRISA  = 0xFF;     // PORTA input

    ADC_Init();        // Initialize ADC module

    while (1) {
        uint16 result  = ADC_Read(0);        // Read channel AN0 (0–1023)
        uint8  numLEDs = result / 128;       // Map to 0–7
        uint8  mask    = (1 << numLEDs) - 1;
        PORTD  = mask;
        Delay_ms(100);
    }
}
