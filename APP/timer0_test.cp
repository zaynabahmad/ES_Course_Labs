#line 1 "D:/ES-Project-Lab/APP/timer0_test.c"
#line 1 "d:/es-project-lab/services/std_types.h"



typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;

typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;

typedef float f32;
typedef double f64;
#line 1 "d:/es-project-lab/mcal/gpio/gpio.h"
#line 1 "d:/es-project-lab/services/std_types.h"
#line 27 "d:/es-project-lab/mcal/gpio/gpio.h"
void GPIO_setPinDirection(u8 port, u8 pin, u8 direction);
void GPIO_setPinValue(u8 port, u8 pin, u8 value);
u8 GPIO_getPinValue(u8 port, u8 pin);
void GPIO_setPortDirection(u8 port, u8 direction);
void GPIO_setPortValue(u8 port, u8 value);
#line 1 "d:/es-project-lab/mcal/timer0/timer0_interface.h"
#line 1 "d:/es-project-lab/services/std_types.h"
#line 7 "d:/es-project-lab/mcal/timer0/timer0_interface.h"
void TIMER0_init(void);


void TIMER0_setPreload(u8 value);


void TIMER0_enableInterrupt(void);


void TIMER0_disableInterrupt(void);
#line 1 "d:/es-project-lab/mcal/exti/exti_interface.h"
#line 1 "d:/es-project-lab/services/std_types.h"
#line 10 "d:/es-project-lab/mcal/exti/exti_interface.h"
void EXTI_init(u8 edge);


void EXTI_setCallback(void (*ptr)(void));


extern volatile u8 exti_flag;
extern volatile u8 timer0_flag;
#line 1 "d:/es-project-lab/hal/led_interface.h"
void LED_Init(u8 port, u8 pin);
void LED_On(u8 port, u8 pin);
void LED_Off(u8 port, u8 pin);
void LED_Toggle(u8 port, u8 pin);
#line 6 "D:/ES-Project-Lab/APP/timer0_test.c"
void app_timer0_test(void) {

 LED_Init( 3 ,  1 );

 TIMER0_init();
 TIMER0_setPreload(0);
 TIMER0_enableInterrupt();

 while(1) {

 if (timer0_flag == 1) {


 static u8 state = 0;
 state ^= 1;
 LED_Toggle( 3 ,  1 );

 TIMER0_setPreload(0);
 timer0_flag = 0;
 }
 }
}
