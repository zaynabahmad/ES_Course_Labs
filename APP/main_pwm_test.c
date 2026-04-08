/*
 * main_pwm_test.c
 * PWM + EXT_INT Test – PIC16F877A @ 8 MHz
 * MikroC PRO for PIC
 *
 * Function:
 *   Each press of the button on RB0 cycles the PWM duty cycle:
 *   25% → 50% → 75% → 100% → 25% → ...
 *   The PWM signal comes out on RC2 (CCP1).
 *   RC3 drives the H-Bridge direction pin (stays HIGH = forward).
 *
 * Wiring:
 *   RB0        → Push button (other side to GND, internal pull-up active)
 *   RC2 (CCP1) → H-Bridge PWM input
 *   RC3        → H-Bridge direction input
 */

#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/EXT_INT/EXT_INT_Interface.h"
#include "../MCAL/PWM/PWM_interface.h"

/* H-Bridge direction pin */
#define HBRIDGE_DIR_PORT    GPIO_PORTC
#define HBRIDGE_DIR_PIN     GPIO_PIN3

void main(void)
{
    /* 1. GPIO – sets PORTA/PORTB directions from GPIO_config.h */
    GPIO_Init();

    /* 2. H-Bridge direction pin: output, drive HIGH (forward) */
    GPIO_SetPinDirection(HBRIDGE_DIR_PORT, HBRIDGE_DIR_PIN, GPIO_OUTPUT);
    GPIO_SetPinValue(HBRIDGE_DIR_PORT, HBRIDGE_DIR_PIN, GPIO_HIGH);

    /* 3. PWM – starts at 25% (defined in PWM_config.h) on RC2 */
    PWM_Init();

    /* 4. Register callback BEFORE enabling the interrupt */
    EXT_INT_SetCallback(PWM_NextDutyLevel);

    /* 5. Init configures RB0 as input and sets falling edge */
    EXT_INT_Init();

    /* 6. Enable RB0 interrupt + global interrupts (GIE) */
    EXT_INT_Enable();

    /* Main loop does nothing – all work is done in the ISR */
    while (1)
    {
    }
}
