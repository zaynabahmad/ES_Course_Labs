#line 1 "D:/Lab1_Task1/MCAL/GPIO/GPIO_program.c"
#line 1 "d:/lab1_task1/mcal/gpio/gpio_interface.h"
#line 1 "d:/lab1_task1/mcal/gpio/../../services/std_types.h"



typedef unsigned char uint8;
typedef unsigned int uint16;
typedef unsigned long uint32;
#line 32 "d:/lab1_task1/mcal/gpio/gpio_interface.h"
void GPIO_SetPinDirection(uint8 port, uint8 pin, uint8 direction);
void GPIO_WritePin(uint8 port, uint8 pin, uint8 value);
uint8 GPIO_ReadPin(uint8 port, uint8 pin);
#line 1 "d:/lab1_task1/mcal/gpio/../../services/bit_math.h"
#line 7 "D:/Lab1_Task1/MCAL/GPIO/GPIO_program.c"
void GPIO_SetPinDirection(uint8 port, uint8 pin, uint8 direction)
{
 switch(port)
 {
 case  0 :
 if(direction ==  1 )  ((TRISA) |= (1 << (pin))) ;
 else  ((TRISA) &= ~(1 << (pin))) ;
 break;

 case  1 :
 if(direction ==  1 )  ((TRISB) |= (1 << (pin))) ;
 else  ((TRISB) &= ~(1 << (pin))) ;
 break;

 case  2 :
 if(direction ==  1 )  ((TRISC) |= (1 << (pin))) ;
 else  ((TRISC) &= ~(1 << (pin))) ;
 break;

 case  3 :
 if(direction ==  1 )  ((TRISD) |= (1 << (pin))) ;
 else  ((TRISD) &= ~(1 << (pin))) ;
 break;

 case  4 :
 if(direction ==  1 )  ((TRISE) |= (1 << (pin))) ;
 else  ((TRISE) &= ~(1 << (pin))) ;
 break;

 default: break;
 }
}

void GPIO_WritePin(uint8 port, uint8 pin, uint8 value)
{
 switch(port)
 {
 case  0 :
 if(value ==  1 )  ((PORTA) |= (1 << (pin))) ;
 else  ((PORTA) &= ~(1 << (pin))) ;
 break;

 case  1 :
 if(value ==  1 )  ((PORTB) |= (1 << (pin))) ;
 else  ((PORTB) &= ~(1 << (pin))) ;
 break;

 case  2 :
 if(value ==  1 )  ((PORTC) |= (1 << (pin))) ;
 else  ((PORTC) &= ~(1 << (pin))) ;
 break;

 case  3 :
 if(value ==  1 )  ((PORTD) |= (1 << (pin))) ;
 else  ((PORTD) &= ~(1 << (pin))) ;
 break;

 case  4 :
 if(value ==  1 )  ((PORTE) |= (1 << (pin))) ;
 else  ((PORTE) &= ~(1 << (pin))) ;
 break;

 default: break;
 }
}

uint8 GPIO_ReadPin(uint8 port, uint8 pin)
{
 uint8 val =  0 ;

 switch(port)
 {
 case  0 : val =  (((PORTA) >> (pin)) & 1) ; break;
 case  1 : val =  (((PORTB) >> (pin)) & 1) ; break;
 case  2 : val =  (((PORTC) >> (pin)) & 1) ; break;
 case  3 : val =  (((PORTD) >> (pin)) & 1) ; break;
 case  4 : val =  (((PORTE) >> (pin)) & 1) ; break;
 default: break;
 }

 return val;
}
