#line 1 "C:/Users/OmarT/Downloads/Task3_Interrupt/Interrupt/HAL/LED/LED.c"
#line 1 "c:/users/omart/downloads/task3_interrupt/interrupt/hal/led/led_interface.h"
#line 1 "c:/users/omart/downloads/task3_interrupt/interrupt/hal/led/../../mcal/gpio/gpio_interface.h"
#line 1 "c:/users/omart/downloads/task3_interrupt/interrupt/hal/led/../../mcal/gpio/../../services/std_types.h"




typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;


typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;


typedef float f32;
typedef double f64;
typedef long double f128;
#line 21 "c:/users/omart/downloads/task3_interrupt/interrupt/hal/led/../../mcal/gpio/gpio_interface.h"
void GPIO_SetPinDirection(u8 Port, u8 Pin, u8 Direction);
void GPIO_SetPinValue(u8 Port, u8 Pin, u8 Value);
u8 GPIO_GetPinValue(u8 Port, u8 Pin);
#line 6 "c:/users/omart/downloads/task3_interrupt/interrupt/hal/led/led_interface.h"
void LED_Init(unsigned char port, unsigned char pin);
void LED_Toggle(unsigned char port, unsigned char pin);
#line 1 "c:/users/omart/downloads/task3_interrupt/interrupt/hal/led/../../services/std_types.h"
#line 4 "C:/Users/OmarT/Downloads/Task3_Interrupt/Interrupt/HAL/LED/LED.c"
void LED_Init(unsigned char port, unsigned char pin){
 GPIO_SetPinDirection(port, pin,  1 );
 GPIO_SetPinValue(port, pin,  0 );
}

void LED_Toggle(unsigned char port, unsigned char pin){
 if(GPIO_GetPinValue(port, pin))
 GPIO_SetPinValue(port, pin,  0 );
 else
 GPIO_SetPinValue(port, pin,  1 );
}
