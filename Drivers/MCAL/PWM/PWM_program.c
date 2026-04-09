#include "../../MCAL/PWM/PWM_private.h"
#include "../../MCAL/PWM/PWM_interface.h"
#include "../../MCAL/PWM/PWM_config.h"
#include "../../SERVICES/BIT_MATH.h"

void PWM_voidInit(void) {
    // RC2/CCP1 as output
    GPIO_voidSetPinDirection(GPIO_PORTC, GPIO_PIN2, GPIO_PIN_OUTPUT);
    
    // PWM mode: 00001100
    CCP1CON = 0x0C;
    
    // Timer2 for PWM (1kHz @ 8MHz)
    PR2 = 249;
    T2CON = 0x04;  // Timer2 ON, prescaler 1:4
}

void PWM_voidSetDutyCycle(uint8 Copy_Duty) {
    uint16 duty_10bit = (Copy_Duty * 1023) / 100;
    CCPR1L = (duty_10bit >> 2);
    CCP1CONbits.CCP1Y = (duty_10bit & 0x02) >> 1;
    CCP1CONbits.CCP1X = duty_10bit & 0x01;
}