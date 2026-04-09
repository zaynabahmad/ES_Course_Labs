#line 1 "E:/embedded/Drivers_Project/APP/pwm_test.c"
#line 1 "e:/embedded/drivers_project/app/pwm_test.h"



void PWM_Test(void);
#line 1 "e:/embedded/drivers_project/app/../mcal/pwm/pwm_interface.h"



void PWM_Init(void);
void PWM_SetDuty(unsigned int duty);
#line 4 "E:/embedded/Drivers_Project/APP/pwm_test.c"
void PWM_Test(void)
{
 unsigned int duty = 0;

 PWM_Init();

 while(1)
 {
 PWM_SetDuty(duty);
 duty += 10;

 if(duty > 1023)
 duty = 0;

 Delay_ms(100);
 }
}
