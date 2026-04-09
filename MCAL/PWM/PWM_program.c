#include "PWM_private.h"
#include "PWM_interface.h"

// Initialize PWM (Fast PWM - Non-inverting)
void PWM_Init()
{
    // Set PB3 (OC0) as output
    DDRB |= (1 << 3);

    // Fast PWM mode
    TCCR0 |= (1 << 3) | (1 << 6);

    // Non-inverting mode
    TCCR0 |= (1 << 5);

    // Prescaler = 64
    TCCR0 |= (1 << 0) | (1 << 1);
}

// Set duty cycle (0 → 255)
void PWM_SetDutyCycle(unsigned char duty)
{
    OCR0 = duty;
}