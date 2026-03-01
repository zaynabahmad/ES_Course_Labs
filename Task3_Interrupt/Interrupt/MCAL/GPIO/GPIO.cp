#line 1 "C:/Users/OmarT/Downloads/Task3_Interrupt/Interrupt/MCAL/GPIO/GPIO.c"
#line 1 "c:/users/omart/downloads/task3_interrupt/interrupt/mcal/gpio/gpio_interface.h"
#line 1 "c:/users/omart/downloads/task3_interrupt/interrupt/mcal/gpio/../../services/std_types.h"




typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;


typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;


typedef float f32;
typedef double f64;
typedef long double f128;
#line 21 "c:/users/omart/downloads/task3_interrupt/interrupt/mcal/gpio/gpio_interface.h"
void GPIO_SetPinDirection(u8 Port, u8 Pin, u8 Direction);
void GPIO_SetPinValue(u8 Port, u8 Pin, u8 Value);
u8 GPIO_GetPinValue(u8 Port, u8 Pin);
#line 1 "c:/users/omart/downloads/task3_interrupt/interrupt/mcal/gpio/../../services/std_types.h"
#line 5 "C:/Users/OmarT/Downloads/Task3_Interrupt/Interrupt/MCAL/GPIO/GPIO.c"
void GPIO_SetPinDirection(u8 Port, u8 Pin, u8 Direction){
 switch(Port){
 case  0 : TRISA |= (Direction << Pin); break;
 case  1 : TRISB |= (Direction << Pin); break;
 case  2 : TRISC |= (Direction << Pin); break;
 case  3 : TRISD |= (Direction << Pin); break;
 case  4 : TRISE |= (Direction << Pin); break;
 }
}

void GPIO_SetPinValue(u8 Port, u8 Pin, u8 Value){
 switch(Port){
 case  0 :
 if(Value) PORTA |= (1 << Pin);
 else PORTA &= ~(1 << Pin);
 break;
 case  1 :
 if(Value) PORTB |= (1 << Pin);
 else PORTB &= ~(1 << Pin);
 break;
 case  2 :
 if(Value) PORTC |= (1 << Pin);
 else PORTC &= ~(1 << Pin);
 break;
 case  3 :
 if(Value) PORTD |= (1 << Pin);
 else PORTD &= ~(1 << Pin);
 break;
 case  4 :
 if(Value) PORTE |= (1 << Pin);
 else PORTE &= ~(1 << Pin);
 break;
 }
}

u8 GPIO_GetPinValue(u8 Port, u8 Pin){
 u8 val = 0;
 switch(Port){
 case  0 : val = (PORTA >> Pin) & 1; break;
 case  1 : val = (PORTB >> Pin) & 1; break;
 case  2 : val = (PORTC >> Pin) & 1; break;
 case  3 : val = (PORTD >> Pin) & 1; break;
 case  4 : val = (PORTE >> Pin) & 1; break;
 }
 return val;
}
