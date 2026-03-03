#line 1 "D:/Materials/Y4Spring/Embedded/Labs/Lab2Task1/HAL/LED/LED_impelemntation.c"
#line 1 "d:/materials/y4spring/embedded/labs/lab2task1/hal/led/led_interface.h"
#line 1 "d:/materials/y4spring/embedded/labs/lab2task1/hal/led/../../mcal/gpio/gpio_interface.h"
#line 1 "d:/materials/y4spring/embedded/labs/lab2task1/hal/led/../../mcal/gpio/gpio_private.h"
#line 1 "c:/users/public/documents/mikroelektronika/mikroc pro for pic/include/stdbool.h"



 typedef char _Bool;
#line 7 "d:/materials/y4spring/embedded/labs/lab2task1/hal/led/../../mcal/gpio/gpio_interface.h"
void GPIO_Init(void);

void setpindirection(unsigned char port, unsigned char pin,  _Bool  direction);

void setpinvalue(unsigned char port, unsigned char pin,  _Bool  value);

unsigned char getpinvalue(unsigned char port, unsigned char pin);
#line 6 "d:/materials/y4spring/embedded/labs/lab2task1/hal/led/led_interface.h"
void LED_Init(unsigned char port1, unsigned char pin1,
 unsigned char port2, unsigned char pin2);

void LED_On(unsigned char port, unsigned char pin);

void LED_Off(unsigned char port, unsigned char pin);
#line 3 "D:/Materials/Y4Spring/Embedded/Labs/Lab2Task1/HAL/LED/LED_impelemntation.c"
void LED_Init(unsigned char port1, unsigned char pin1,
 unsigned char port2, unsigned char pin2)
{
 setpindirection(port1, pin1,  0 );
 setpindirection(port2, pin2,  0 );

 setpinvalue(port1, pin1,  0 );
 setpinvalue(port2, pin2,  0 );
}

void LED_On(unsigned char port, unsigned char pin)
{
 setpinvalue(port, pin,  1 );
}

void LED_Off(unsigned char port, unsigned char pin)
{
 setpinvalue(port, pin,  0 );
}
