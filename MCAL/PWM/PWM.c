#include "PWM_interface.h"
#include "PWM_private.h"
#include "../../SERVICES/BIT_MATH.h"

void PWM1_Init(void) 
{
    /* 1. Set PWM Period to ~500Hz (Assuming a 4MHz Oscillator) */
    /* PR2 = (Fosc / (4 * Fpwm * TMR2_Prescaler)) - 1 */
    /* PR2 = (4000000 / (4 * 500 * 16)) - 1 = 124 */
    PR2 = 124;

    /* 2. Configure CCP1 module for PWM mode */
    /* CCP1M3:CCP1M0 = 1100 (0x0C) */
    CCP1CON = 0x0C;

    /* 3. Configure and Enable Timer2 */
    /* Set Prescaler to 16 -> T2CKPS1:T2CKPS0 = 1X */
    SET_BIT(T2CON, 1);
    
    /* Enable Timer2 -> TMR2ON = 1 */
    SET_BIT(T2CON, 2);
}

void PWM1_SetDutyCycle(uint8 duty_cycle_percent) 
{
    /* Calculate the 10-bit duty cycle value */
    /* Total resolution = (PR2 + 1) * 4 */
    uint16 total_resolution = (PR2 + 1) * 4; 
    uint16 duty_value = (duty_cycle_percent * total_resolution) / 100;
    
    /* Store the top 8 bits in CCPR1L */
    CCPR1L = (duty_value >> 2);
    
    /* Store the bottom 2 bits in CCP1CON<5:4> */
    CCP1CON &= 0xCF; /* Clear bits 4 and 5 first */
    CCP1CON |= ((duty_value & 0x03) << 4); /* Set bits 4 and 5 */
}