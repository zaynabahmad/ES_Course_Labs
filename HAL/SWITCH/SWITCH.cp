#line 1 "C:/Users/Z B O O K/Downloads/Test/ES_Course_Labs-main/HAL/SWITCH/SWITCH.c"
#line 1 "c:/users/z b o o k/downloads/test/es_course_labs-main/hal/switch/../../services/std_types.h"




typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;


typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;


typedef float f32;
typedef double f64;
typedef long double f128;
#line 1 "c:/users/z b o o k/downloads/test/es_course_labs-main/hal/switch/switch_interface.h"
#line 1 "c:/users/z b o o k/downloads/test/es_course_labs-main/hal/switch/../../services/std_types.h"
#line 6 "c:/users/z b o o k/downloads/test/es_course_labs-main/hal/switch/switch_interface.h"
void SWITCH_Init(u8 pin);
#line 1 "c:/users/z b o o k/downloads/test/es_course_labs-main/hal/switch/../../mcal/gpio/gpio_interface.h"
#line 1 "c:/users/z b o o k/downloads/test/es_course_labs-main/hal/switch/../../mcal/gpio/../../services/std_types.h"
#line 31 "c:/users/z b o o k/downloads/test/es_course_labs-main/hal/switch/../../mcal/gpio/gpio_interface.h"
void GPIO_SetPinDirection(u8 Port, u8 Pin, u8 Direction);
void GPIO_SetPinValue(u8 Port, u8 Pin, u8 Value);
u8 GPIO_GetPinValue(u8 Port, u8 Pin);
void GPIO_Init(void);
#line 5 "C:/Users/Z B O O K/Downloads/Test/ES_Course_Labs-main/HAL/SWITCH/SWITCH.c"
void SWITCH_Init(u8 pin) {

 GPIO_SetPinDirection( 1 , pin,  1 );
}
