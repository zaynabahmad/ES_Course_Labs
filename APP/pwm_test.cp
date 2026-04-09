#line 1 "D:/ES-Project-Lab/APP/pwm_test.c"
#line 1 "d:/es-project-lab/services/std_types.h"



typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;

typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;

typedef float f32;
typedef double f64;
#line 1 "d:/es-project-lab/mcal/pwm/pwm_interface.h"
#line 1 "d:/es-project-lab/services/std_types.h"
#line 6 "d:/es-project-lab/mcal/pwm/pwm_interface.h"
void PWM_Init(void);
void PWM_Start(void);
void PWM_Stop(void);
void PWM_SetDutyPercent(u8 dutyPercent);
#line 4 "D:/ES-Project-Lab/APP/pwm_test.c"
void app_pwm_test(void)
{
 u8 duty = 0;
 u16 delayValue = 0;

 PWM_Init();

 while(1)
 {
 for(duty = 0; duty <= 100; duty += 10)
 {
 PWM_SetDutyPercent(duty);

 for(delayValue = 0; delayValue < 10000; delayValue++)
 {
 ;
 }
 }

 for(duty = 100; duty >= 10; duty -= 10)
 {
 PWM_SetDutyPercent(duty);

 for(delayValue = 0; delayValue < 10000; delayValue++)
 {
 ;
 }
 }
 }
}
