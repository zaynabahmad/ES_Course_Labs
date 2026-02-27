# 1 "../ES_Course_Labs/HAL/Switch/Switch.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 295 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:\\Program Files\\Microchip\\xc8\\v3.10\\pic\\include/language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "../ES_Course_Labs/HAL/Switch/Switch.c" 2
# 1 "../ES_Course_Labs/HAL/Switch/Switch_interface.h" 1



# 1 "../ES_Course_Labs/HAL/Switch/../../SERVICES/STD_TYPES.h" 1




typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;


typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;


typedef float f32;
typedef double f64;
typedef long double f128;
# 5 "../ES_Course_Labs/HAL/Switch/Switch_interface.h" 2






void Switch_Init(u8 Port, u8 Pin);
u8 switch_read(u8 Port, u8 Pin);
# 2 "../ES_Course_Labs/HAL/Switch/Switch.c" 2
# 1 "../ES_Course_Labs/HAL/Switch/../../MCAL/GPIO/GPIO_interface.h" 1
# 31 "../ES_Course_Labs/HAL/Switch/../../MCAL/GPIO/GPIO_interface.h"
void GPIO_SetPinDirection(u8 Port, u8 Pin, u8 Direction);
void GPIO_SetPinValue(u8 Port, u8 Pin, u8 Value);
u8 GPIO_GetPinValue(u8 Port, u8 Pin);
void GPIO_Init(void);
# 3 "../ES_Course_Labs/HAL/Switch/Switch.c" 2

void Switch_Init(u8 Port, u8 Pin)
{
    GPIO_SetPinDirection(Port, Pin, 1);
}

u8 switch_read(u8 Port, u8 Pin) {
 return GPIO_GetPinValue(Port, Pin);
}
