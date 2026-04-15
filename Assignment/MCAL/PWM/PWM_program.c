 #include "../SERVICES/STD_TYPES.h"
#include "../SERVICES/BIT_MATH.h"

#include "../MCAL/PWM/PWM_interface.h"
#include "../MCAL/PWM/PWM_private.h"

void PWM_voidInit(void)
{
    // Set PWM mode
    CCP1CON=0b00001100;

    // Set frequency
    PR2=124;

    //  Timer2 with prescaler = 16
    T2CON=0b00000111;
}

void PWM_voidSetDutyCycle(u8 duty)
{
    u16 value;

    // Convert % to value
    value=(u16)((duty*1023UL)/100);

    CCPR1L=value>>2;

    CCP1CON&=0b11001111;
    CCP1CON|=(value&0x03)<<4;
}