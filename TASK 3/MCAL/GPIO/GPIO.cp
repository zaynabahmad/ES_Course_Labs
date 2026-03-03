#line 1 "D:/Education/TASK 3/MCAL/GPIO/GPIO.c"
#line 1 "d:/education/task 3/mcal/gpio/../../services/std_types.h"



typedef unsigned char uint8;
typedef unsigned short int uint16;
typedef unsigned long int uint32;
#line 1 "d:/education/task 3/mcal/gpio/../../services/bit_math.h"
#line 1 "d:/education/task 3/mcal/gpio/gpio_interface.h"









void MGPIO_vSetPinDirection(uint8 Copy_u8Port, uint8 Copy_u8Pin, uint8 Copy_u8Direction);
void MGPIO_vTogglePin(uint8 Copy_u8Port, uint8 Copy_u8Pin);
#line 5 "D:/Education/TASK 3/MCAL/GPIO/GPIO.c"
void MGPIO_vSetPinDirection(uint8 Copy_u8Port, uint8 Copy_u8Pin, uint8 Copy_u8Direction) {
 if (Copy_u8Port ==  1 ) {
 if (Copy_u8Direction ==  1 )  (TRISB |= (1 << Copy_u8Pin)) ;
 else  (TRISB &= ~(1 << Copy_u8Pin)) ;
 } else if (Copy_u8Port ==  3 ) {
 if (Copy_u8Direction ==  1 )  (TRISD |= (1 << Copy_u8Pin)) ;
 else  (TRISD &= ~(1 << Copy_u8Pin)) ;
 }
}

void MGPIO_vTogglePin(uint8 Copy_u8Port, uint8 Copy_u8Pin) {
 if (Copy_u8Port ==  1 )  (PORTB ^= (1 << Copy_u8Pin)) ;
 else if (Copy_u8Port ==  3 )  (PORTD ^= (1 << Copy_u8Pin)) ;
}
