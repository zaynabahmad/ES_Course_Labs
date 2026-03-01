#line 1 "C:/Users/OmarT/Downloads/TASKKKK1/TASK11/APP/main.c"
#line 1 "c:/users/omart/downloads/taskkkk1/task11/app/../mcal/gpio/gpio_interface.h"
#line 1 "c:/users/omart/downloads/taskkkk1/task11/app/../mcal/gpio/../../services/std_types.h"




typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;


typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;


typedef float f32;
typedef double f64;
typedef long double f128;
#line 31 "c:/users/omart/downloads/taskkkk1/task11/app/../mcal/gpio/gpio_interface.h"
void GPIO_SetPinDirection(u8 Port, u8 Pin, u8 Direction);
void GPIO_SetPinValue(u8 Port, u8 Pin, u8 Value);
u8 GPIO_GetPinValue(u8 Port, u8 Pin);
void GPIO_Init(void);
#line 1 "c:/users/omart/downloads/taskkkk1/task11/app/../hal/led/led_interface.h"
#line 1 "c:/users/omart/downloads/taskkkk1/task11/app/../hal/led/../../services/std_types.h"
#line 1 "c:/users/omart/downloads/taskkkk1/task11/app/../hal/led/led_interface.h"
#line 1 "c:/users/omart/downloads/taskkkk1/task11/app/../hal/led/../../mcal/gpio/gpio_interface.h"
#line 13 "c:/users/omart/downloads/taskkkk1/task11/app/../hal/led/led_interface.h"
void LED_Init(void);
void LED_On(u8 led);
void LED_Off(u8 led);
void LED_Toggle(u8 led);
#line 1 "c:/users/omart/downloads/taskkkk1/task11/app/../services/std_types.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for pic/include/built_in.h"
#line 11 "C:/Users/OmarT/Downloads/TASKKKK1/TASK11/APP/main.c"
void ShortSequence(void)
{
 LED_On( 1 );
 LED_On( 2 );
 Delay_ms(200);
 LED_Off( 1 );
 LED_Off( 2 );
 Delay_ms(200);
}

void LongSequence(void)
{
 LED_On( 1 );
 LED_On( 2 );
 Delay_ms(500);
 LED_Off( 1 );
 LED_Off( 2 );
 Delay_ms(500);
}

void main(void)
{
 GPIO_Init();
 LED_Init();

 GPIO_SetPinDirection( 1 ,  0 ,  1 );
 GPIO_SetPinDirection( 1 ,  1 ,  1 );

 while(1)
 {
 if(GPIO_GetPinValue( 1 ,  0 ) == 0)
 ShortSequence();
 else if(GPIO_GetPinValue( 1 ,  1 ) == 0)
 LongSequence();
 else
 {
 LED_Off( 1 );
 LED_Off( 2 );
 }
 }
}
