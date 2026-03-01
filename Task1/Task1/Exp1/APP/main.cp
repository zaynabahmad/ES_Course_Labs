#line 1 "C:/Users/OmarT/OneDrive/PHASE 2/ES_Course_Labs-main/ES_Course_Labs-main/APP/main.c"
#line 1 "c:/users/omart/onedrive/phase 2/es_course_labs-main/es_course_labs-main/app/../hal/led/led_interface.h"
#line 1 "c:/users/omart/onedrive/phase 2/es_course_labs-main/es_course_labs-main/app/../hal/led/../../services/std_types.h"




typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;


typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;


typedef float f32;
typedef double f64;
typedef long double f128;
#line 10 "c:/users/omart/onedrive/phase 2/es_course_labs-main/es_course_labs-main/app/../hal/led/led_interface.h"
void LED_Init(u8 Port, u8 Pin);
void LED_On(u8 Port, u8 Pin);
void LED_Off(u8 Port, u8 Pin);
void LED_Toggle(u8 Port, u8 Pin);
#line 1 "c:/users/omart/onedrive/phase 2/es_course_labs-main/es_course_labs-main/app/../mcal/gpio/gpio_interface.h"
#line 1 "c:/users/omart/onedrive/phase 2/es_course_labs-main/es_course_labs-main/app/../mcal/gpio/../../services/std_types.h"
#line 31 "c:/users/omart/onedrive/phase 2/es_course_labs-main/es_course_labs-main/app/../mcal/gpio/gpio_interface.h"
void GPIO_SetPinDirection(u8 Port, u8 Pin, u8 Direction);
void GPIO_SetPinValue(u8 Port, u8 Pin, u8 Value);
u8 GPIO_GetPinValue(u8 Port, u8 Pin);
void GPIO_Init(void);
#line 8 "C:/Users/OmarT/OneDrive/PHASE 2/ES_Course_Labs-main/ES_Course_Labs-main/APP/main.c"
void delay(void)
{
 unsigned int i;
 for(i = 0; i < 50000; i++);
}

void main(void)
{

 unsigned char port =  1 ;
 unsigned char pin =  0 ;


 LED_Init(port, pin);

 while(1)
 {

 LED_On(port, pin);
 delay();
 LED_Off(port, pin);
 delay();
 }
}
