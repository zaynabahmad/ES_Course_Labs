#ifndef PWM_CONFIG_H
#define PWM_CONFIG_H

/*==================================================
 * Timer2 Prescaler Selection
 *--------------------------------------------------
 * Choose one of the following values:
 * 1   ? No prescaling
 * 4   ? Divide by 4
 * 16  ? Divide by 16
 *==================================================*/
#define PWM_TMR2_PRESCALER   16


/*==================================================
 * PWM Period Configuration (PR2 Register)
 *--------------------------------------------------
 * The PWM frequency depends on PR2 value:
 *
 * PWM Period = (PR2 + 1) × 4 × Tosc × Prescaler
 *
 * Example Calculation:
 * Fosc = 8 MHz  ? Tosc = 0.125 µs
 * Prescaler = 16
 * Desired frequency = 1 kHz ? Period = 1000 µs
 *
 * 1000 = (PR2 + 1) × 4 × 0.125 × 16
 * 1000 = (PR2 + 1) × 8
 * PR2 = 124
 *==================================================*/
#define PWM_PR2_VALUE        124

#endif