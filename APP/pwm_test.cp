#line 1 "E:/study/embedded/labs/lab-tasks/ES_Course_Labs-main/APP/pwm_test.c"
#line 1 "e:/study/embedded/labs/lab-tasks/es_course_labs-main/mcal/pwm/pwm_interface.h"
#line 1 "e:/study/embedded/labs/lab-tasks/es_course_labs-main/mcal/pwm/../../services/std_types.h"




typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;


typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;


typedef float f32;
typedef double f64;
typedef long double f128;
#line 13 "e:/study/embedded/labs/lab-tasks/es_course_labs-main/mcal/pwm/pwm_interface.h"
void PWM_Init(void);
void PWM_SetDutyCycle(u8 Duty);
void PWM_Start(void);
void PWM_Stop(void);
#line 3 "E:/study/embedded/labs/lab-tasks/ES_Course_Labs-main/APP/pwm_test.c"
void pwm_test_run(void) {
 PWM_Init();

 PWM_SetDutyCycle(50);
 PWM_Start();
}
