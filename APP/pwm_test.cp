#line 1 "D:/Uni/Y4 S2/Embedded Systems/Final/APP/pwm_test.c"
#line 1 "d:/uni/y4 s2/embedded systems/final/mcal/pwm/pwm_interface.h"
#line 1 "d:/uni/y4 s2/embedded systems/final/services/std_types.h"



typedef unsigned char u8;
typedef unsigned int u16;
#line 15 "d:/uni/y4 s2/embedded systems/final/mcal/pwm/pwm_interface.h"
void PWM_voidInit(void);

unsigned char PWM_voidSetDuty(unsigned char duty_percent);

void PWM_voidSetDutyRaw(unsigned char raw);

void PWM_voidStop(void);
#line 3 "D:/Uni/Y4 S2/Embedded Systems/Final/APP/pwm_test.c"
void PWM_Test(void)
{
 PWM_voidInit();

 while (1)
 {
 PWM_voidSetDuty(25);
 TIMER0_voidDelayMs(2000);

 PWM_voidSetDuty(50);
 TIMER0_voidDelayMs(2000);

 PWM_voidSetDuty(75);
 TIMER0_voidDelayMs(2000);

 PWM_voidSetDuty(100);
 TIMER0_voidDelayMs(2000);
 }
}
