#line 1 "C:/Users/OmarT/Downloads/TASKKKK1/TASK11/HAL/LED/LED.c"
#line 1 "c:/users/omart/downloads/taskkkk1/task11/hal/led/../../services/std_types.h"




typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;


typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;


typedef float f32;
typedef double f64;
typedef long double f128;
#line 1 "c:/users/omart/downloads/taskkkk1/task11/hal/led/led_interface.h"
#line 1 "c:/users/omart/downloads/taskkkk1/task11/hal/led/../../services/std_types.h"
#line 1 "c:/users/omart/downloads/taskkkk1/task11/hal/led/led_interface.h"
#line 1 "c:/users/omart/downloads/taskkkk1/task11/hal/led/../../mcal/gpio/gpio_interface.h"
#line 1 "c:/users/omart/downloads/taskkkk1/task11/hal/led/../../mcal/gpio/../../services/std_types.h"
#line 31 "c:/users/omart/downloads/taskkkk1/task11/hal/led/../../mcal/gpio/gpio_interface.h"
void GPIO_SetPinDirection(u8 Port, u8 Pin, u8 Direction);
void GPIO_SetPinValue(u8 Port, u8 Pin, u8 Value);
u8 GPIO_GetPinValue(u8 Port, u8 Pin);
void GPIO_Init(void);
#line 13 "c:/users/omart/downloads/taskkkk1/task11/hal/led/led_interface.h"
void LED_Init(void);
void LED_On(u8 led);
void LED_Off(u8 led);
void LED_Toggle(u8 led);
#line 1 "c:/users/omart/downloads/taskkkk1/task11/hal/led/../../mcal/gpio/gpio_interface.h"
#line 1 "c:/users/omart/downloads/taskkkk1/task11/hal/led/led_private.h"
#line 6 "C:/Users/OmarT/Downloads/TASKKKK1/TASK11/HAL/LED/LED.c"
void LED_Init(void)
{
 GPIO_SetPinDirection( 0 ,  0 ,  0 );
 GPIO_SetPinDirection( 0 ,  1 ,  0 );

 GPIO_SetPinValue( 0 ,  0 ,  0 );
 GPIO_SetPinValue( 0 ,  1 ,  0 );
}

void LED_On(u8 led)
{
 if(led ==  1 ) GPIO_SetPinValue( 0 ,  0 ,  1 );
 if(led ==  2 ) GPIO_SetPinValue( 0 ,  1 ,  1 );
}

void LED_Off(u8 led)
{
 if(led ==  1 ) GPIO_SetPinValue( 0 ,  0 ,  0 );
 if(led ==  2 ) GPIO_SetPinValue( 0 ,  1 ,  0 );
}

void LED_Toggle(u8 led)
{
 if(led ==  1 ) GPIO_SetPinValue( 0 ,  0 , !GPIO_GetPinValue( 0 ,  0 ));
 if(led ==  2 ) GPIO_SetPinValue( 0 ,  1 , !GPIO_GetPinValue( 0 ,  1 ));
}
