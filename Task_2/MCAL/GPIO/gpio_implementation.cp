#line 1 "D:/University/Spring_26/Embedded/Task_2/MCAL/GPIO/gpio_implementation.c"
#line 1 "d:/university/spring_26/embedded/task_2/mcal/gpio/../../services/std_types.h"




typedef unsigned char u8;
typedef signed short int s16;
typedef unsigned short int u16;
typedef unsigned long int u32;




typedef unsigned char bool_t;
#line 1 "d:/university/spring_26/embedded/task_2/mcal/gpio/../../services/bit_math.h"
#line 1 "d:/university/spring_26/embedded/task_2/mcal/gpio/gpio_interface.h"
#line 1 "d:/university/spring_26/embedded/task_2/mcal/gpio/../../services/std_types.h"
#line 24 "d:/university/spring_26/embedded/task_2/mcal/gpio/gpio_interface.h"
void set_pin_direction(u8 port, u8 pin, u8 direction);
void set_pin_value(u8 port, u8 pin, u8 value);
u8 get_pin_value(u8 port, u8 pin);
void toggle_pin(u8 port, u8 pin);
#line 7 "D:/University/Spring_26/Embedded/Task_2/MCAL/GPIO/gpio_implementation.c"
void set_pin_direction(u8 port, u8 pin, u8 direction) {
 switch(port) {
 case  0 :
 if(direction ==  0 ) {
  (TRISA &= ~(1 << pin)) ;
 } else if (direction ==  1 ) {
  (TRISA |= (1 << pin)) ;
 }
 break;
 case  1 :
 if(direction ==  0 ) {
  (TRISB &= ~(1 << pin)) ;
 } else if (direction ==  1 ) {
  (TRISB |= (1 << pin)) ;
 }
 break;
 case  2 :
 if(direction ==  0 ) {
  (TRISC &= ~(1 << pin)) ;
 } else if (direction ==  1 ) {
  (TRISC |= (1 << pin)) ;
 }
 break;
 case  3 :
 if(direction ==  0 ) {
  (TRISD &= ~(1 << pin)) ;
 } else if (direction ==  1 ) {
  (TRISD |= (1 << pin)) ;
 }
 break;
 case  4 :
 if(direction ==  0 ) {
  (TRISE &= ~(1 << pin)) ;
 } else if (direction ==  1 ) {
  (TRISE |= (1 << pin)) ;
 }
 break;
 }
}

void set_pin_value(u8 port, u8 pin, u8 value) {
 switch(port) {
 case  0 :
 if(value ==  1 ) {
  (PORTA |= (1 << pin)) ;
 } else {
  (PORTA &= ~(1 << pin)) ;
 }
 break;
 case  1 :
 if(value ==  1 ) {
  (PORTB |= (1 << pin)) ;
 } else {
  (PORTB &= ~(1 << pin)) ;
 }
 break;
 case  2 :
 if(value ==  1 ) {
  (PORTC |= (1 << pin)) ;
 } else {
  (PORTC &= ~(1 << pin)) ;
 }
 break;
 case  3 :
 if(value ==  1 ) {
  (PORTD |= (1 << pin)) ;
 } else {
  (PORTD &= ~(1 << pin)) ;
 }
 break;
 case  4 :
 if(value ==  1 ) {
  (PORTE |= (1 << pin)) ;
 } else {
  (PORTE &= ~(1 << pin)) ;
 }
 break;
 }
}

u8 get_pin_value(u8 port, u8 pin) {
 switch(port) {
 case  0 : return  ((PORTA >> pin) & 1) ;
 case  1 : return  ((PORTB >> pin) & 1) ;
 case  2 : return  ((PORTC >> pin) & 1) ;
 case  3 : return  ((PORTD >> pin) & 1) ;
 case  4 : return  ((PORTE >> pin) & 1) ;
 default: return 0;
 }
}
void toggle_pin(u8 port, u8 pin) {
 switch(port) {
 case  0 :
 PORTA ^= (1 << pin);
 break;

 case  1 :
 PORTB ^= (1 << pin);
 break;

 case  2 :
 PORTC ^= (1 << pin);
 break;

 case  3 :
 PORTD ^= (1 << pin);
 break;

 case  4 :
 PORTE ^= (1 << pin);
 break;
 }
}
