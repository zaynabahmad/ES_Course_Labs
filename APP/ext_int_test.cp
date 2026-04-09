#line 1 "E:/study/embedded/labs/lab-tasks/ES_Course_Labs-main/APP/ext_int_test.c"
#line 1 "e:/study/embedded/labs/lab-tasks/es_course_labs-main/app/../mcal/ext_int/ext_int_interface.h"
#line 1 "e:/study/embedded/labs/lab-tasks/es_course_labs-main/app/../mcal/ext_int/../../services/std_types.h"




typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;


typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;


typedef float f32;
typedef double f64;
typedef long double f128;
#line 1 "e:/study/embedded/labs/lab-tasks/es_course_labs-main/app/../mcal/ext_int/../gpio/gpio_interface.h"
#line 1 "e:/study/embedded/labs/lab-tasks/es_course_labs-main/app/../mcal/ext_int/../gpio/../../services/std_types.h"
#line 31 "e:/study/embedded/labs/lab-tasks/es_course_labs-main/app/../mcal/ext_int/../gpio/gpio_interface.h"
void GPIO_SetPinDirection(unsigned char Port, u8 Pin, u8 Direction);
void GPIO_SetPinValue(u8 Port, u8 Pin, u8 Value);
u8 GPIO_GetPinValue(u8 Port, u8 Pin);
void GPIO_Init(void);
#line 1 "e:/study/embedded/labs/lab-tasks/es_course_labs-main/app/../mcal/ext_int/../../services/bit_math.h"
#line 1 "e:/study/embedded/labs/lab-tasks/es_course_labs-main/app/../mcal/ext_int/ext_int_config.h"
#line 1 "e:/study/embedded/labs/lab-tasks/es_course_labs-main/app/../mcal/ext_int/ext_int_private.h"
#line 22 "e:/study/embedded/labs/lab-tasks/es_course_labs-main/app/../mcal/ext_int/ext_int_interface.h"
void EXT_INT_Init(void);
void EXT_INT_Enable(void);
void EXT_INT_Disable(void);
void EXT_INT_SetEdge(u8 Edgetype);
void EXT_INT_SetCallback(void (*Callback)(void));
void EXT_INT_ISR(void);
#line 1 "e:/study/embedded/labs/lab-tasks/es_course_labs-main/app/../hal/led/led_interface.h"
#line 1 "e:/study/embedded/labs/lab-tasks/es_course_labs-main/app/../hal/led/../../services/std_types.h"
#line 10 "e:/study/embedded/labs/lab-tasks/es_course_labs-main/app/../hal/led/led_interface.h"
void LED_Init(u8 Port, u8 Pin);
void LED_On(u8 Port, u8 Pin);
void LED_Off(u8 Port, u8 Pin);
void LED_Toggle(u8 Port, u8 Pin);
#line 5 "E:/study/embedded/labs/lab-tasks/ES_Course_Labs-main/APP/ext_int_test.c"
void Button_Pressed_Callback(void) {
 LED_Toggle( 2 ,  0 );
}

void ext_int_test_run(void) {

 LED_Init( 2 ,  0 );


 EXT_INT_Init();


 EXT_INT_SetCallback(Button_Pressed_Callback);


 EXT_INT_SetEdge( 0 );


 EXT_INT_Enable();

 while(1) {

 }
}
