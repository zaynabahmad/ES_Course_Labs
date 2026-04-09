#line 1 "D:/ES-Project-Lab/MCAL/GPIO/gpio.c"
#line 1 "d:/es-project-lab/services/std_types.h"



typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;

typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;

typedef float f32;
typedef double f64;
#line 1 "d:/es-project-lab/services/bit_math.h"
#line 1 "d:/es-project-lab/mcal/gpio/gpio_prv.h"
#line 1 "d:/es-project-lab/mcal/gpio/gpio.h"
#line 1 "d:/es-project-lab/services/std_types.h"
#line 27 "d:/es-project-lab/mcal/gpio/gpio.h"
void GPIO_setPinDirection(u8 port, u8 pin, u8 direction);
void GPIO_setPinValue(u8 port, u8 pin, u8 value);
u8 GPIO_getPinValue(u8 port, u8 pin);
void GPIO_setPortDirection(u8 port, u8 direction);
void GPIO_setPortValue(u8 port, u8 value);
#line 7 "D:/ES-Project-Lab/MCAL/GPIO/gpio.c"
void GPIO_setPinDirection(u8 port, u8 pin, u8 direction) {
 if(pin > 7) return;
 if (direction ==  1 ) {
 switch (port) {
 case  0 :  (( *((volatile u8*)0x85) ) |= (1 << (pin))) ; break;
 case  1 :  (( *((volatile u8*)0x86) ) |= (1 << (pin))) ; break;
 case  2 :  (( *((volatile u8*)0x87) ) |= (1 << (pin))) ; break;
 case  3 :  (( *((volatile u8*)0x88) ) |= (1 << (pin))) ; break;
 case  4 :  (( *((volatile u8*)0x89) ) |= (1 << (pin))) ; break;
 }
 } else {
 switch (port) {
 case  0 :  (( *((volatile u8*)0x85) ) &= ~(1 << (pin))) ; break;
 case  1 :  (( *((volatile u8*)0x86) ) &= ~(1 << (pin))) ; break;
 case  2 :  (( *((volatile u8*)0x87) ) &= ~(1 << (pin))) ; break;
 case  3 :  (( *((volatile u8*)0x88) ) &= ~(1 << (pin))) ; break;
 case  4 :  (( *((volatile u8*)0x89) ) &= ~(1 << (pin))) ; break;
 }
 }
}

void GPIO_setPinValue(u8 port, u8 pin, u8 value) {
 if(pin > 7) return;
 if (value ==  1 ) {
 switch (port) {
 case  0 :  (( *((volatile u8*)0x05) ) |= (1 << (pin))) ; break;
 case  1 :  (( *((volatile u8*)0x06) ) |= (1 << (pin))) ; break;
 case  2 :  (( *((volatile u8*)0x07) ) |= (1 << (pin))) ; break;
 case  3 :  (( *((volatile u8*)0x08) ) |= (1 << (pin))) ; break;
 case  4 :  (( *((volatile u8*)0x09) ) |= (1 << (pin))) ; break;
 }
 } else {
 switch (port) {
 case  0 :  (( *((volatile u8*)0x05) ) &= ~(1 << (pin))) ; break;
 case  1 :  (( *((volatile u8*)0x06) ) &= ~(1 << (pin))) ; break;
 case  2 :  (( *((volatile u8*)0x07) ) &= ~(1 << (pin))) ; break;
 case  3 :  (( *((volatile u8*)0x08) ) &= ~(1 << (pin))) ; break;
 case  4 :  (( *((volatile u8*)0x09) ) &= ~(1 << (pin))) ; break;
 }
 }
}

u8 GPIO_getPinValue(u8 port, u8 pin) {
 u8 pinVal = 0;
 if(pin > 7) return 0;
 switch (port) {
 case  0 : pinVal =  ((( *((volatile u8*)0x05) ) >> (pin)) & 0x01) ; break;
 case  1 : pinVal =  ((( *((volatile u8*)0x06) ) >> (pin)) & 0x01) ; break;
 case  2 : pinVal =  ((( *((volatile u8*)0x07) ) >> (pin)) & 0x01) ; break;
 case  3 : pinVal =  ((( *((volatile u8*)0x08) ) >> (pin)) & 0x01) ; break;
 case  4 : pinVal =  ((( *((volatile u8*)0x09) ) >> (pin)) & 0x01) ; break;
 }
 return pinVal;
}

void GPIO_setPortDirection(u8 port, u8 direction) {
 switch(port) {
 case  0 :  *((volatile u8*)0x85)  = direction; break;
 case  1 :  *((volatile u8*)0x86)  = direction; break;
 case  2 :  *((volatile u8*)0x87)  = direction; break;
 case  3 :  *((volatile u8*)0x88)  = direction; break;
 case  4 :  *((volatile u8*)0x89)  = direction; break;
 }
}

void GPIO_setPortValue(u8 port, u8 value) {
 switch(port) {
 case  0 :  *((volatile u8*)0x05)  = value; break;
 case  1 :  *((volatile u8*)0x06)  = value; break;
 case  2 :  *((volatile u8*)0x07)  = value; break;
 case  3 :  *((volatile u8*)0x08)  = value; break;
 case  4 :  *((volatile u8*)0x09)  = value; break;
 }
}
