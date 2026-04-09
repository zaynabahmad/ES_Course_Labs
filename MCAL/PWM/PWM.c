#include "PWM_interface.h"
#include "PWM_private.h"
#include "PWM_config.h"

void PWM1_Init(void) 
{
    // 1. Set the PWM Period
    PR2 = PWM1_PR2_VALUE;
    
    // 2. Set CCP1 to PWM mode (Bits 3:0 = 1100)
    CCP1CON = 0x0C; 
    
    // 3. Set Timer2 Prescaler to 16 and turn Timer2 ON
    // Bit 2 turns Timer2 ON. Bits 1:0 set Prescaler to 16. (0000 0110 = 0x06)
    T2CON = 0x06; 
    
    // 4. Initialize with 0% duty cycle (Motor stopped)
    PWM1_SetDutyCycle(0);
}

void PWM1_SetDutyCycle(u8 duty_percentage) 
{
    unsigned int max_value;
    unsigned int duty_value;

    if(duty_percentage > 100) 
    {
        duty_percentage = 100;
    }
    
    // The maximum 10-bit value depends on PR2 (Formula: 4 * (PR2 + 1))
    max_value = 4 * (PWM1_PR2_VALUE + 1);
    
    // Calculate the required 10-bit value based on the requested percentage
    duty_value = (unsigned int)(((unsigned long)duty_percentage * max_value) / 100);
    
    // Write the 8 Most Significant Bits to CCPR1L
    CCPR1L = (u8)(duty_value >> 2);
    
    // Write the 2 Least Significant Bits to CCP1CON (Bits 5 and 4)
    CCP1CON = (CCP1CON & 0xCF) | ((duty_value & 0x03) << 4);
}