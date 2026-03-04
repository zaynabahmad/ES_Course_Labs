#line 1 "D:/Lab1_Task1/HAL/LED/LED_program.c"
#line 1 "d:/lab1_task1/hal/led/led_interface.h"
#line 1 "d:/lab1_task1/hal/led/../../services/std_types.h"



typedef unsigned char uint8;
typedef unsigned int uint16;
typedef unsigned long uint32;
#line 11 "d:/lab1_task1/hal/led/led_interface.h"
void LED_Init(uint8 port, uint8 pin);
void LED_On(uint8 port, uint8 pin);
void LED_Off(uint8 port, uint8 pin);
void LED_Toggle(uint8 port, uint8 pin);
#line 1 "d:/lab1_task1/hal/led/../../mcal/gpio/gpio_interface.h"
#line 1 "d:/lab1_task1/hal/led/../../mcal/gpio/../../services/std_types.h"
#line 32 "d:/lab1_task1/hal/led/../../mcal/gpio/gpio_interface.h"
void GPIO_SetPinDirection(uint8 port, uint8 pin, uint8 direction);
void GPIO_WritePin(uint8 port, uint8 pin, uint8 value);
uint8 GPIO_ReadPin(uint8 port, uint8 pin);
#line 4 "D:/Lab1_Task1/HAL/LED/LED_program.c"
void LED_Init(uint8 port, uint8 pin)
{
 GPIO_SetPinDirection(port, pin,  0 );
 GPIO_WritePin(port, pin,  0 );
}

void LED_On(uint8 port, uint8 pin)
{
 GPIO_WritePin(port, pin,  1 );
}

void LED_Off(uint8 port, uint8 pin)
{
 GPIO_WritePin(port, pin,  0 );
}

void LED_Toggle(uint8 port, uint8 pin)
{
 uint8 current = GPIO_ReadPin(port, pin);
 GPIO_WritePin(port, pin, !current);
}
