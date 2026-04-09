#include "ADC_private.h"

// Initialize ADC
void ADC_Init()
{
    // AVCC reference
    ADMUX |= (1 << 6);

    // Enable ADC
    ADCSRA |= (1 << 7);

    // Prescaler = 64
    ADCSRA |= (1 << 1) | (1 << 2);
}

// Read from channel (0 → 7)
unsigned int ADC_Read(char channel)
{
    // Select channel
    ADMUX &= 0xE0;
    ADMUX |= channel;

    // Start conversion
    ADCSRA |= (1 << 6);

    // Wait until done
    while (ADCSRA & (1 << 6));

    // Return result (10-bit)
    return (ADCL | (ADCH << 8));
}