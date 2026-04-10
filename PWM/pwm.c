// Purpose: Creates PWM signal for controlling brightness or speed
// PWM = fast on/off switching that looks like analog voltage

#include "pwm.h"

void PWM_Init(void) {
    // Setup CCP1 module for PWM on pin RC2
    TRISC &= ~(1 << 2);  // Make RC2 output
    CCP1CON = 0x0C;      // PWM mode (bits 3-2 = 11)
    PR2 = 255;           // PWM period (255 = 1kHz at 8MHz)
    T2CON = 0x07;        // Timer2 on, prescaler 1:16
}

void PWM_SetDutyCycle(uint8 duty) {
    // duty: 0 = 0%, 128 = 50%, 255 = 100%
    CCPR1L = duty >> 2;           // High 8 bits
    CCP1CONbits.DC1B = duty & 3;  // Low 2 bits
}

void PWM_Start(void) {
    TMR2ON = 1;  // Turn on Timer2 (starts PWM)
}

void PWM_Stop(void) {
    TMR2ON = 0;  // Turn off Timer2 (stops PWM)
}