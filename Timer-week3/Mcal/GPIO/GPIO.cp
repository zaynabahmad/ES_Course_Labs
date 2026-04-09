#line 1 "D:/Timer-week3/Mcal/GPIO/GPIO.c"
#line 1 "d:/timer-week3/mcal/gpio/gpio_interface.h"
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
#line 31 "d:/timer-week3/mcal/gpio/gpio_interface.h"
void GPIO_SetPinDirection(u8 Port, u8 Pin, u8 Direction);
void GPIO_SetPinValue(u8 Port, u8 Pin, u8 Value);
void GPIO_TogglePinValue(u8 Port, u8 Pin);
u8 GPIO_GetPinValue(u8 Port, u8 Pin);
#line 1 "d:/timer-week3/mcal/gpio/../../services/bit_math.h"
#line 5 "D:/Timer-week3/Mcal/GPIO/GPIO.c"
void GPIO_SetPinDirection(u8 Port, u8 Pin, u8 Direction)
{
 if (Direction ==  0 )
 {
 switch (Port)
 {
 case  0 :  ((TRISA) &= ~(1 << (Pin))) ; break;
 case  1 :  ((TRISB) &= ~(1 << (Pin))) ; break;
 case  2 :  ((TRISC) &= ~(1 << (Pin))) ; break;
 case  3 :  ((TRISD) &= ~(1 << (Pin))) ; break;
 case  4 :  ((TRISE) &= ~(1 << (Pin))) ; break;
 }
 }
 else if (Direction ==  1 )
 {
 switch (Port)
 {
 case  0 :  ((TRISA) |= (1 << (Pin))) ; break;
 case  1 :  ((TRISB) |= (1 << (Pin))) ; break;
 case  2 :  ((TRISC) |= (1 << (Pin))) ; break;
 case  3 :  ((TRISD) |= (1 << (Pin))) ; break;
 case  4 :  ((TRISE) |= (1 << (Pin))) ; break;
 }
 }
}

void GPIO_SetPinValue(u8 Port, u8 Pin, u8 Value)
{
 if (Value ==  1 )
 {
 switch (Port)
 {
 case  0 :  ((PORTA) |= (1 << (Pin))) ; break;
 case  1 :  ((PORTB) |= (1 << (Pin))) ; break;
 case  2 :  ((PORTC) |= (1 << (Pin))) ; break;
 case  3 :  ((PORTD) |= (1 << (Pin))) ; break;
 case  4 :  ((PORTE) |= (1 << (Pin))) ; break;
 }
 }
 else if (Value ==  0 )
 {
 switch (Port)
 {
 case  0 :  ((PORTA) &= ~(1 << (Pin))) ; break;
 case  1 :  ((PORTB) &= ~(1 << (Pin))) ; break;
 case  2 :  ((PORTC) &= ~(1 << (Pin))) ; break;
 case  3 :  ((PORTD) &= ~(1 << (Pin))) ; break;
 case  4 :  ((PORTE) &= ~(1 << (Pin))) ; break;
 }
 }
}

void GPIO_TogglePinValue(u8 Port, u8 Pin)
{
 switch (Port)
 {
 case  0 :  ((PORTA) ^= (1 << (Pin))) ; break;
 case  1 :  ((PORTB) ^= (1 << (Pin))) ; break;
 case  2 :  ((PORTC) ^= (1 << (Pin))) ; break;
 case  3 :  ((PORTD) ^= (1 << (Pin))) ; break;
 case  4 :  ((PORTE) ^= (1 << (Pin))) ; break;
 }
}

u8 GPIO_GetPinValue(u8 Port, u8 Pin)
{
 u8 PinValue = 0;
 switch (Port)
 {
 case  0 : PinValue =  (((PORTA) >> (Pin)) & 1) ; break;
 case  1 : PinValue =  (((PORTB) >> (Pin)) & 1) ; break;
 case  2 : PinValue =  (((PORTC) >> (Pin)) & 1) ; break;
 case  3 : PinValue =  (((PORTD) >> (Pin)) & 1) ; break;
 case  4 : PinValue =  (((PORTE) >> (Pin)) & 1) ; break;
 }
 return PinValue;
}
