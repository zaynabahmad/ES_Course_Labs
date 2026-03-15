#include "PWM_interface.h"
static volatile u8 prescaler_value=16;
#include "PWM_interface.h"

static u8 g_u8CurrentDutyPercent = 0;
static u8 g_u8CurrentPrescaler = 16;

void PWM_voidInit(void) {
    GPIO_SetPinDirection(GPIO_PORTC, CCP1_PIN, GPIO_OUTPUT);

    // Default: 1kHz @ 8MHz, 16x Prescaler
    PR2 = 124;
    CCPR1L = 0;
    CCP1CON = (CCP1CON & 0xF0) | 0x0C; // PWM Mode
    T2CON = 0x06;                      // Prescaler 16, Timer2 ON
}

void PWM_setfrequency(u16 Copy_u16Frequency) {
     u32 PR2_calc;
    if (Copy_u16Frequency == 0) return;

    // PR2 = (Fosc / (4 * F_pwm * Prescaler)) - 1
    PR2_calc = (8000000UL / ((u32)Copy_u16Frequency * 4 * g_u8CurrentPrescaler)) - 1;

    if (PR2_calc <= 255) {
        PR2 = (u8)PR2_calc;
        // CRITICAL: Recalculate duty cycle because the PR2 "ceiling" changed
        PWM_SetDutyCycle(g_u8CurrentDutyPercent);
    }
}

void PWM_SetDutyCycle(u8 Copy_u8DutyPercent) {
     u32 local_val;
    if (Copy_u8DutyPercent > 100) Copy_u8DutyPercent = 100;

    g_u8CurrentDutyPercent = Copy_u8DutyPercent;

    // Duty_Value = (Percentage / 100) * (PR2 + 1) * 4
    // We use u32 to prevent the multiplication overflow (e.g., 100 * 125 * 4 = 50,000)
    local_val = ((u32)g_u8CurrentDutyPercent * (PR2 + 1) * 4) / 100;

    CCPR1L = (u8)(local_val >> 2);
    CCP1CON = (CCP1CON & 0xCF) | ((u8)(local_val & 0x03) << 4);
}
void PWM_setprescaler(u8 Copy_u8Prescaler)
{
    T2CON &= 0xFC; // Clear current prescaler bits (0 and 1)
    
    switch(Copy_u8Prescaler)
    {
        case 1:  /* Bits 00 */
            break; 
        case 4:  /* Bits 01 */
            T2CON |= 0x01;
            break;
        case 16: /* Bits 1x (using 10) */
            T2CON |= 0x02;
            break;
    }
    prescaler_value = Copy_u8Prescaler;
}


void PWM_enable(void)
{
    /* Bit 2 of T2CON is TMR2ON */
    T2CON |= (1 << 2);
}