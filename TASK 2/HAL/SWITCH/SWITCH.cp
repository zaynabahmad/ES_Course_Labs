#line 1 "D:/Education/LAB1/HAL/SWITCH/SWITCH.c"
#line 1 "d:/education/lab1/hal/switch/../../mcal/gpio/gpio_interface.h"









void GPIO_SetPinDirection(char port, char pin, char direction);
void GPIO_WritePin(char port, char pin, char value);
char GPIO_ReadPin(char port, char pin);
#line 1 "d:/education/lab1/hal/switch/switch_interface.h"



void SWITCH_Init(char port, char pin);
char SWITCH_Read(char port, char pin);
#line 4 "D:/Education/LAB1/HAL/SWITCH/SWITCH.c"
void SWITCH_Init(char port, char pin)
{
 GPIO_SetPinDirection(port, pin,  1 );
}

char SWITCH_Read(char port, char pin)
{
 return GPIO_ReadPin(port, pin);
}
