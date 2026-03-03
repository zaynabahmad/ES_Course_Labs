#line 1 "D:/Education/TASK 3/HAL/LED/LED.c"
#line 1 "d:/education/task 3/hal/led/../../services/std_types.h"



typedef unsigned char uint8;
typedef unsigned short int uint16;
typedef unsigned long int uint32;
#line 1 "d:/education/task 3/hal/led/../../services/bit_math.h"
#line 1 "d:/education/task 3/hal/led/../../mcal/gpio/gpio_interface.h"









void MGPIO_vSetPinDirection(uint8 Copy_u8Port, uint8 Copy_u8Pin, uint8 Copy_u8Direction);
void MGPIO_vTogglePin(uint8 Copy_u8Port, uint8 Copy_u8Pin);
#line 1 "d:/education/task 3/hal/led/led_config.h"
#line 1 "d:/education/task 3/hal/led/led_interface.h"



void HLED_vInit(void);
void HLED_vToggle(void);
#line 7 "D:/Education/TASK 3/HAL/LED/LED.c"
void HLED_vInit(void) {
 MGPIO_vSetPinDirection( 3 ,  0 ,  0 );
}

void HLED_vToggle(void) {
 MGPIO_vTogglePin( 3 ,  0 );
}
