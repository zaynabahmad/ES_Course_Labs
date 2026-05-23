#line 1 "D:/Uni/Y4 S2/Embedded Systems/Final/MCAL/PWM/PWM_program.c"
#line 1 "d:/uni/y4 s2/embedded systems/final/services/std_types.h"



typedef unsigned char u8;
typedef unsigned int u16;
#line 1 "d:/uni/y4 s2/embedded systems/final/services/bit_math.h"
#line 1 "d:/uni/y4 s2/embedded systems/final/mcal/pwm/pwm_private.h"
#line 1 "d:/uni/y4 s2/embedded systems/final/mcal/pwm/pwm_interface.h"
#line 1 "d:/uni/y4 s2/embedded systems/final/services/std_types.h"
#line 15 "d:/uni/y4 s2/embedded systems/final/mcal/pwm/pwm_interface.h"
void PWM_voidInit(void);

unsigned char PWM_voidSetDuty(unsigned char duty_percent);

void PWM_voidSetDutyRaw(unsigned char raw);

void PWM_voidStop(void);
#line 7 "D:/Uni/Y4 S2/Embedded Systems/Final/MCAL/PWM/PWM_program.c"
void PWM_voidInit(void)
{
  (*(volatile unsigned char*)0x87)  &= ~(1<< 2u ) ;

  (*(volatile unsigned char*)0x92)  =  124u ;

  (*(volatile unsigned char*)0x17)  =  0x0Cu ;

  (*(volatile unsigned char*)0x15)  = 0x00u;

  (*(volatile unsigned char*)0x11)  = 0x00u;
  (*(volatile unsigned char*)0x12)  =  0x01u ;
  (*(volatile unsigned char*)0x12)  |= (1<< 2 ) ;
}


unsigned char PWM_voidSetDuty(unsigned char duty_percent)
{
 unsigned int raw;


 if (duty_percent > 100u)
 {
 return  0xFFu ;
 }

 raw = ((unsigned int)duty_percent *  255u ) / 100u;


  (*(volatile unsigned char*)0x15)  = (unsigned char)raw;

  (*(volatile unsigned char*)0x17)  &= ~(1<< 4 ) ;
  (*(volatile unsigned char*)0x17)  &= ~(1<< 5 ) ;

 return  0u ;
}


void PWM_voidSetDutyRaw(unsigned char raw)
{

  (*(volatile unsigned char*)0x15)  = raw;
  (*(volatile unsigned char*)0x17)  &= ~(1<< 4 ) ;
  (*(volatile unsigned char*)0x17)  &= ~(1<< 5 ) ;
}


void PWM_voidStop(void)
{

  (*(volatile unsigned char*)0x12)  &= ~(1<< 2 ) ;


  (*(volatile unsigned char*)0x17)  = 0x00u;


  (*(volatile unsigned char*)0x15)  = 0x00u;
}
