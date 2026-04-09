#line 1 "D:/ES-Project-Lab/APP/exti_test.c"
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
#line 5 "D:/ES-Project-Lab/APP/exti_test.c"
void toggle_led(void) {
 static u8 state = 0;
 if(state == 0) {
 LED_On( 3 ,  1 );
 state = 1;
 } else {
 LED_off( 3 ,  1 );
 state = 0;
 }
}

void app_exti_test(void) {
 GPIO_setPinDirection( 3 ,  1 ,  0 );
 GPIO_setPinDirection( 1 ,  0 ,  1 );

 EXTI_init( 0 );

 while(1) {
 if (exti_flag == 1) {
 toggle_led();
 exti_flag = 0;
 }
 }
}
