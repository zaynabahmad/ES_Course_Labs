#line 1 "D:/Timer-week3/APP/Main.c"
#line 1 "d:/timer-week3/hal/led.h"
#line 1 "d:/timer-week3/services/std_types.h"




typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;


typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;


typedef float f32;
typedef double f64;
typedef long double f128;
#line 6 "d:/timer-week3/hal/led.h"
void LED_Init(u8 Port, u8 Pin);
void LED_On(u8 Port, u8 Pin);
void LED_Off(u8 Port, u8 Pin);
void LED_Toggle(u8 Port, u8 Pin);
#line 1 "d:/timer-week3/mcal/gpio/gpio_interface.h"
#line 1 "d:/timer-week3/services/std_types.h"
#line 31 "d:/timer-week3/mcal/gpio/gpio_interface.h"
void GPIO_SetPinDirection(u8 Port, u8 Pin, u8 Direction);
void GPIO_SetPinValue(u8 Port, u8 Pin, u8 Value);
void GPIO_TogglePinValue(u8 Port, u8 Pin);
u8 GPIO_GetPinValue(u8 Port, u8 Pin);
#line 1 "d:/timer-week3/timer/timer_interface.h"
#line 1 "d:/timer-week3/services/std_types.h"
#line 5 "d:/timer-week3/timer/timer_interface.h"
void TIMER0_Init(void);
void TIMER0_SetCallback_1Sec(void (*ptr)(void));
void TIMER0_SetCallback_2Sec(void (*ptr)(void));
#line 6 "D:/Timer-week3/APP/Main.c"
void Toggle_LED2_1Sec(void)
{
 LED_Toggle( 1 ,  2 );
}


void Toggle_LED1_2Sec(void)
{
 LED_Toggle( 1 ,  1 );
}

void main()
{

 LED_Init( 1 ,  1 );
 LED_Init( 1 ,  2 );


 TIMER0_SetCallback_1Sec(Toggle_LED2_1Sec);
 TIMER0_SetCallback_2Sec(Toggle_LED1_2Sec);


 TIMER0_Init();


 while(1)
 {

 }
}
