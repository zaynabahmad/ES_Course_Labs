#line 1 "D:/mikroC PRO for PIC/Examples/APP/PWM_test.c"
#line 1 "d:/mikroc pro for pic/examples/app/../mcal/pwm/pwm_interface.h"





void PWM_voidInit(void);
void PWM_voidSetDutyCycle(u8 duty);
#line 3 "D:/mikroC PRO for PIC/Examples/APP/PWM_test.c"
void PWM_Test(void)
{
 PWM_voidInit();

 while(1)
 {
 PWM_voidSetDutyCycle(25);
 Delay_ms(1000);

 PWM_voidSetDutyCycle(75);
 Delay_ms(1000);
 }
}
