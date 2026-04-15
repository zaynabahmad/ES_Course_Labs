#line 1 "D:/mikroC PRO for PIC/Examples/MCAL/PWM/PWM_program.c"






void PWM_voidInit(void)
{

 CCP1CON = 0b00001100;


 PR2 = 124;


 T2CON = 0b00000111;
}

void PWM_voidSetDutyCycle(u8 duty)
{
 u16 value;


 value = (u16)((duty * 1023UL) / 100);

 CCPR1L = value >> 2;

 CCP1CON &= 0b11001111;
 CCP1CON |= (value & 0x03) << 4;
}
