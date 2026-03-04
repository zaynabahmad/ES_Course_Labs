#line 1 "D:/Lab1_Task1/HAL/SWITCH/SWITCH_program.c"
#line 1 "d:/lab1_task1/hal/switch/switch_interface.h"
#line 1 "d:/lab1_task1/hal/switch/../../services/std_types.h"



typedef unsigned char uint8;
typedef unsigned int uint16;
typedef unsigned long uint32;
#line 11 "d:/lab1_task1/hal/switch/switch_interface.h"
void SWITCH_Init(uint8 port, uint8 pin);
uint8 SWITCH_Read(uint8 port, uint8 pin);
#line 1 "d:/lab1_task1/hal/switch/../../mcal/gpio/gpio_interface.h"
#line 1 "d:/lab1_task1/hal/switch/../../mcal/gpio/../../services/std_types.h"
#line 32 "d:/lab1_task1/hal/switch/../../mcal/gpio/gpio_interface.h"
void GPIO_SetPinDirection(uint8 port, uint8 pin, uint8 direction);
void GPIO_WritePin(uint8 port, uint8 pin, uint8 value);
uint8 GPIO_ReadPin(uint8 port, uint8 pin);
#line 4 "D:/Lab1_Task1/HAL/SWITCH/SWITCH_program.c"
void SWITCH_Init(uint8 port, uint8 pin)
{

 GPIO_SetPinDirection(port, pin,  1 );
}

uint8 SWITCH_Read(uint8 port, uint8 pin)
{
 return GPIO_ReadPin(port, pin);
}
