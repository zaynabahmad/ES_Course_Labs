#include "../../SERVICES/Bit_Math.h"
#include "PWM.h"

/* Register Definitions (Private to PWM.c) */
#define CCP1CON     *((volatile u8*)0x17)
#define CCPR1L      *((volatile u8*)0x15)
#define PR2         *((volatile u8*)0x92)
#define T2CON       *((volatile u8*)0x12)
#define TRISC       *((volatile u8*)0x87)

void M_PWM_voidInit(void) {
    /* 1. Set RC2/CCP1 as Output (CCP1 is pin 17 on PIC16F877A) */
    CLR_BIT(TRISC, 2);
    
    /* 2. Set PWM Period (Frequency)
       At 8MHz, PR2 = 255 gives F_pwm = 8MHz / (4 * 1 * (255+1)) = 7.81 kHz */
    PR2 = 255;
    
    /* 3. Configure CCP1 Module for PWM mode (0x0C = 0000 1100) */
    CCP1CON = 0x0C;
    
    /* 4. Timer2 Configuration:
       Bit 2: TMR2ON = 1 (Start Timer)
       Bits 1-0: Prescaler = 00 (1:1) */
    T2CON = 0x04;
}

void M_PWM_voidSetDutyCycle(u8 copy_u8Duty) {
    /* Since PR2 is 255, copy_u8Duty (0-255) directly maps to 0-100% 
       High resolution (10-bit) uses bits in CCP1CON, but for this lab, 
       8-bit resolution (using CCPR1L) is perfectly sufficient. */
    CCPR1L = copy_u8Duty;
}