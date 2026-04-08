#include "PWM_interface.h"
#include "PWM_private.h"

void PWM_Init(void)
{
    // RC2 as output (CCP1 pin)
    TRISC &= ~(1 << 2);

    // Set PWM mode
    CCP1CON = 0b00001100;

    // Set PWM period
    PR2 = 249;   // Example for ~5kHz

    // Timer2 ON + prescaler 16
    T2CON = 0b00000111;
}

void PWM_SetDutyCycle(unsigned char duty)
{
    // duty from 0 ? 100 (%)
    unsigned int value = (duty * 1023) / 100;

    CCPR1L = value >> 2;
    CCP1CON &= 0xCF;
    CCP1CON |= (value & 0x03) << 4;
}