#line 1 "C:/Users/Z B O O K/Downloads/Test/ES_Course_Labs-main/APP/main.c"
#line 1 "c:/users/z b o o k/downloads/test/es_course_labs-main/services/std_types.h"




typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;


typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;


typedef float f32;
typedef double f64;
typedef long double f128;
#line 1 "c:/users/z b o o k/downloads/test/es_course_labs-main/mcal/gpio/gpio_interface.h"
#line 1 "c:/users/z b o o k/downloads/test/es_course_labs-main/mcal/gpio/../../services/std_types.h"
#line 31 "c:/users/z b o o k/downloads/test/es_course_labs-main/mcal/gpio/gpio_interface.h"
void GPIO_SetPinDirection(u8 Port, u8 Pin, u8 Direction);
void GPIO_SetPinValue(u8 Port, u8 Pin, u8 Value);
u8 GPIO_GetPinValue(u8 Port, u8 Pin);
void GPIO_Init(void);
#line 1 "c:/users/z b o o k/downloads/test/es_course_labs-main/mcal/ext_int/ext_int0_interface.h"
#line 1 "c:/users/z b o o k/downloads/test/es_course_labs-main/mcal/ext_int/../../services/std_types.h"
#line 11 "c:/users/z b o o k/downloads/test/es_course_labs-main/mcal/ext_int/ext_int0_interface.h"
void EXT_INT0_Init(void);
void EXT_INT0_Enable(void);
void EXT_INT0_Disable(void);
void EXT_INT0_SetEdge(u8 edge_type);
void EXT_INT0_SetCallback(void (*ptr)(void));
#line 1 "c:/users/z b o o k/downloads/test/es_course_labs-main/hal/switch/switch_interface.h"
#line 1 "c:/users/z b o o k/downloads/test/es_course_labs-main/hal/switch/../../services/std_types.h"
#line 6 "c:/users/z b o o k/downloads/test/es_course_labs-main/hal/switch/switch_interface.h"
void SWITCH_Init(u8 pin);
#line 1 "c:/users/z b o o k/downloads/test/es_course_labs-main/hal/led/led_interface.h"
#line 1 "c:/users/z b o o k/downloads/test/es_course_labs-main/hal/led/../../services/std_types.h"
#line 10 "c:/users/z b o o k/downloads/test/es_course_labs-main/hal/led/led_interface.h"
void LED_Init(u8 Port, u8 Pin);
void LED_On(u8 Port, u8 Pin);
void LED_Off(u8 Port, u8 Pin);
void LED_Toggle(u8 Port, u8 Pin);
#line 11 "C:/Users/Z B O O K/Downloads/Test/ES_Course_Labs-main/APP/main.c"
void App_ToggleLED_ISR(void) {

 Delay_ms(30);


 LED_Toggle( 3 ,  0 );
}

void main() {

 LED_Init( 3 ,  0 );


 SWITCH_Init( 0 );

 EXT_INT0_Init();


 EXT_INT0_SetCallback(App_ToggleLED_ISR);


 EXT_INT0_Enable();


 while (1) {

 }
}
