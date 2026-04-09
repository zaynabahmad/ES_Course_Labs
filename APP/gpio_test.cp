#line 1 "D:/ES-Project-Lab/APP/gpio_test.c"
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
#line 1 "d:/es-project-lab/mcal/gpio/gpio_prv.h"
#line 1 "d:/es-project-lab/hal/led_interface.h"
void LED_Init(u8 port, u8 pin);
void LED_On(u8 port, u8 pin);
void LED_Off(u8 port, u8 pin);
void LED_Toggle(u8 port, u8 pin);
#line 5 "D:/ES-Project-Lab/APP/gpio_test.c"
void dummy_delay(u32 count) {
 volatile u32 i;
 for(i = 0; i < count; i++);
}

void app_gpio_test(void) {

  *((volatile u8*)0x9F)  = 0x06;


 GPIO_setPinDirection( 3 ,  0 ,  0 );
 GPIO_setPinDirection( 1 ,  0 ,  1 );


 GPIO_setPinDirection( 4 ,  0 ,  0 );

 while(1) {
 if(GPIO_getPinValue( 1 ,  0 ) == 1) {
 LED_On( 3 ,  0 );
 GPIO_setPinValue( 4 ,  0 ,  1 );
 } else {
 GPIO_setPinValue( 3 ,  0 ,  0 );
 GPIO_setPinValue( 4 ,  0 ,  0 );
 }
 dummy_delay(1000);
 }
}
