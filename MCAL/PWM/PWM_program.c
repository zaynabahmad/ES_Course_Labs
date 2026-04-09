#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"
#include "PWM_interface.h"
#include "PWM_private.h"

void PWM_voidInit(void) {
    /* Set RC2/CCP1 as Output */
    CLR_BIT(TRISC, 2);

    /* Set PWM Period (PR2) - Standard 4MHz clock results in ~1.2kHz */
    PR2 = 0xFF;

    /* Configure CCP1 for PWM mode */
    CCP1CON = 0x0C; // Bits 3-0 set to 1100

    /* Timer2 Configuration: Prescaler 1:16, Timer ON */
    SET_BIT(T2CON, 1); // Prescaler bit 1
    SET_BIT(T2CON, 2); // Timer2 ON
}

void PWM_voidSetDutyCycle(u8 Copy_u8Duty) {
    u16 Local_u16Value = (u16)(((u32)Copy_u8Duty * 1023) / 100);

    /* Load the 10-bit duty cycle into registers */
    CCPR1L = (u8)(Local_u16Value >> 2);
    CCP1CON &= 0xCF; // Clear bits 4 and 5
    CCP1CON |= (u8)((Local_u16Value & 0x03) << 4);
}