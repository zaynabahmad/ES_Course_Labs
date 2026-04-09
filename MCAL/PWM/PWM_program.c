#include "../../SERVICES/BIT_MATH.h"
#include "../../SERVICES/STD_TYPES.h"
#include "../GPIO/GPIO_interface.h"
#include "PWM_private.h"
#include "PWM_interface.h"

void PWM1_Init(void)
{
    // ?? Set CCP1 pin as output (RC2)
    GPIO_SetPinDirection(GPIO_PORTC, GPIO_PIN2, GPIO_OUTPUT);

    // ?? Set PWM period (example)
    PR2_REG = 249; // ~1kHz @ 4MHz with prescaler 16

    // ?? Set PWM mode
    CCP1CON_REG = 0x0C;

    // ?? Timer2 prescaler = 16
    SET_BIT(T2CON_REG, 0);
    SET_BIT(T2CON_REG, 1);

    // ?? Enable Timer2
    SET_BIT(T2CON_REG, TMR2ON_BIT);
}

void PWM1_SetDuty(u8 duty)
{
    u16 duty_val = ((u16)duty * 1023) / 255;

    // Upper 8 bits
    CCPR1L_REG = duty_val >> 2;

    // Lower 2 bits
    CCP1CON_REG &= 0xCF;
    CCP1CON_REG |= ((duty_val & 0x03) << 4);
}

