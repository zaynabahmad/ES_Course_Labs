#line 1 "D:/ES-Project-Lab/HAL/led_program.c"
#line 1 "d:/es-project-lab/mcal/gpio/gpio.h"
#line 1 "d:/es-project-lab/services/std_types.h"



typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;

typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;

typedef float f32;
typedef double f64;
#line 27 "d:/es-project-lab/mcal/gpio/gpio.h"
void GPIO_setPinDirection(u8 port, u8 pin, u8 direction);
void GPIO_setPinValue(u8 port, u8 pin, u8 value);
u8 GPIO_getPinValue(u8 port, u8 pin);
void GPIO_setPortDirection(u8 port, u8 direction);
void GPIO_setPortValue(u8 port, u8 value);
#line 1 "d:/es-project-lab/hal/led_interface.h"
void LED_Init(u8 port, u8 pin);
void LED_On(u8 port, u8 pin);
void LED_Off(u8 port, u8 pin);
void LED_Toggle(u8 port, u8 pin);
#line 4 "D:/ES-Project-Lab/HAL/led_program.c"
void LED_Init(u8 port, u8 pin)
{
 GPIO_setPinDirection(port, pin,  0 );
}

void LED_On(u8 port, u8 pin)
{
 GPIO_setPinValue(port, pin,  1 );
}

void LED_Off(u8 port, u8 pin)
{
 GPIO_setPinValue(port, pin,  0 );
}

void LED_Toggle(u8 port, u8 pin)
{
 static u8 state = 0;
 state ^= 1;
 GPIO_setPinValue(port, pin, state);
}
