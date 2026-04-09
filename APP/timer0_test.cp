#line 1 "E:/study/embedded/labs/lab-tasks/ES_Course_Labs-main/APP/timer0_test.c"
#line 1 "e:/study/embedded/labs/lab-tasks/es_course_labs-main/mcal/timer_0/timer0_interface.h"
#line 1 "e:/study/embedded/labs/lab-tasks/es_course_labs-main/mcal/timer_0/../../services/std_types.h"




typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;


typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;


typedef float f32;
typedef double f64;
typedef long double f128;
#line 16 "e:/study/embedded/labs/lab-tasks/es_course_labs-main/mcal/timer_0/timer0_interface.h"
void TIMER0_Init(u8 Prescaler);
void TIMER0_SetPreload(u8 Value);
void TIMER0_EnableInterrupt(void);
void TIMER0_SetCallback(void (*ptr)(void));
void TIMER0_ISR(void);
#line 1 "e:/study/embedded/labs/lab-tasks/es_course_labs-main/hal/led/led_interface.h"
#line 1 "e:/study/embedded/labs/lab-tasks/es_course_labs-main/hal/led/../../services/std_types.h"
#line 10 "e:/study/embedded/labs/lab-tasks/es_course_labs-main/hal/led/led_interface.h"
void LED_Init(u8 Port, u8 Pin);
void LED_On(u8 Port, u8 Pin);
void LED_Off(u8 Port, u8 Pin);
void LED_Toggle(u8 Port, u8 Pin);
#line 1 "e:/study/embedded/labs/lab-tasks/es_course_labs-main/mcal/gpio/gpio_interface.h"
#line 1 "e:/study/embedded/labs/lab-tasks/es_course_labs-main/mcal/gpio/../../services/std_types.h"
#line 31 "e:/study/embedded/labs/lab-tasks/es_course_labs-main/mcal/gpio/gpio_interface.h"
void GPIO_SetPinDirection(unsigned char Port, u8 Pin, u8 Direction);
void GPIO_SetPinValue(u8 Port, u8 Pin, u8 Value);
u8 GPIO_GetPinValue(u8 Port, u8 Pin);
void GPIO_Init(void);
#line 5 "E:/study/embedded/labs/lab-tasks/ES_Course_Labs-main/APP/timer0_test.c"
static u16 Overflow_Counter = 0;

void Timer0_Toggle_Callback(void) {
 Overflow_Counter++;

 if (Overflow_Counter >= 30) {
 LED_Toggle( 2 ,  0 );
 Overflow_Counter = 0;
 }
}

void timer0_test_run(void) {
 LED_Init( 2 ,  0 );

 TIMER0_Init( 7 );
 TIMER0_SetCallback(Timer0_Toggle_Callback);
 TIMER0_EnableInterrupt();

 while(1) {
 }
}
