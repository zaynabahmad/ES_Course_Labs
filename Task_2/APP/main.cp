#line 1 "D:/University/Spring_26/Embedded/Task_2/APP/main.c"
#line 1 "d:/university/spring_26/embedded/task_2/app/../services/std_types.h"




typedef unsigned char u8;
typedef signed short int s16;
typedef unsigned short int u16;
typedef unsigned long int u32;




typedef unsigned char bool_t;
#line 1 "d:/university/spring_26/embedded/task_2/app/../mcal/timer/timer_interface.h"
#line 1 "d:/university/spring_26/embedded/task_2/app/../mcal/timer/../../services/std_types.h"
#line 6 "d:/university/spring_26/embedded/task_2/app/../mcal/timer/timer_interface.h"
void TIMER0_Init(void);
void TIMER0_SetPreload(u8 preload);
void TIMER0_SetCallback(void (*ptr)(void));
void TIMER0_ISR_Handler(void);
#line 1 "d:/university/spring_26/embedded/task_2/app/../hal/led/led_interface.h"
#line 1 "d:/university/spring_26/embedded/task_2/app/../hal/led/../../services/std_types.h"
#line 1 "d:/university/spring_26/embedded/task_2/app/../hal/led/../../mcal/gpio/gpio_interface.h"
#line 1 "d:/university/spring_26/embedded/task_2/app/../hal/led/../../mcal/gpio/../../services/std_types.h"
#line 24 "d:/university/spring_26/embedded/task_2/app/../hal/led/../../mcal/gpio/gpio_interface.h"
void set_pin_direction(u8 port, u8 pin, u8 direction);
void set_pin_value(u8 port, u8 pin, u8 value);
u8 get_pin_value(u8 port, u8 pin);
void toggle_pin(u8 port, u8 pin);
#line 7 "d:/university/spring_26/embedded/task_2/app/../hal/led/led_interface.h"
void LED_Init(u8 port, u8 pin);
void LED_ON(u8 port, u8 pin);
void LED_OFF(u8 port, u8 pin);
void LED_Toggle(u8 port, u8 pin);
#line 5 "D:/University/Spring_26/Embedded/Task_2/APP/main.c"
static u16 counter_led1 = 0;
static u16 counter_led2 = 0;


void Timer_Task(void)
{
 counter_led1++;
 counter_led2++;


 if(counter_led2 >= 10)
 {
 LED_Toggle( 2 ,0);
 counter_led2 = 0;
 }


 if(counter_led1 >= 20)
 {
 LED_Toggle( 2 ,1);
 counter_led1 = 0;
 }
}

void main()
{

 LED_Init( 2 ,0);
 LED_Init( 2 ,1);


 TIMER0_SetCallback(Timer_Task);
 TIMER0_Init();

 while(1)
 {

 }
}
