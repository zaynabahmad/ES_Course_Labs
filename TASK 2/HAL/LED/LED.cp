#line 1 "D:/Education/LAB1/HAL/LED/LED.c"
#line 1 "d:/education/lab1/hal/led/../../mcal/gpio/gpio_interface.h"









void GPIO_SetPinDirection(char port, char pin, char direction);
void GPIO_WritePin(char port, char pin, char value);
char GPIO_ReadPin(char port, char pin);
#line 1 "d:/education/lab1/hal/led/led_interface.h"



void LED_Init(char port, char pin);
void LED_On(char port, char pin);
void LED_Off(char port, char pin);
#line 4 "D:/Education/LAB1/HAL/LED/LED.c"
void LED_Init(char port, char pin)
{
 GPIO_SetPinDirection(port, pin,  0 );
}

void LED_On(char port, char pin)
{
 GPIO_WritePin(port, pin,  1 );
}

void LED_Off(char port, char pin)
{
 GPIO_WritePin(port, pin,  0 );
}
