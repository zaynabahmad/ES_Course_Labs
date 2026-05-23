#line 1 "D:/Uni/Y4 S2/Embedded Systems/Final/APP/gpio_test.c"
#line 1 "d:/uni/y4 s2/embedded systems/final/mcal/gpio/gpio_interface.h"
#line 1 "d:/uni/y4 s2/embedded systems/final/services/std_types.h"



typedef unsigned char u8;
typedef unsigned int u16;
#line 12 "d:/uni/y4 s2/embedded systems/final/mcal/gpio/gpio_interface.h"
unsigned char GPIO_voidSetPinDirection(unsigned char port,
 unsigned char pin,
 unsigned char dir);

unsigned char GPIO_voidSetPinValue(unsigned char port,
 unsigned char pin,
 unsigned char val);


unsigned char GPIO_u8GetPinValue(unsigned char port,
 unsigned char pin);

unsigned char GPIO_voidTogglePin(unsigned char port,
 unsigned char pin);

unsigned char GPIO_voidSetPortDirection(unsigned char port,
 unsigned char dir_mask);

unsigned char GPIO_voidSetPortValue(unsigned char port,
 unsigned char value);
#line 3 "D:/Uni/Y4 S2/Embedded Systems/Final/APP/gpio_test.c"
void GPIO_Test(void)
{
 GPIO_voidSetPinDirection('B', 0, OUTPUT);
 GPIO_voidSetPinDirection('B', 1, OUTPUT);

 while (1)
 {
 GPIO_voidSetPinValue('B', 0, HIGH);
 GPIO_voidSetPinValue('B', 1, LOW);
 TIMER0_voidDelayMs(500);

 GPIO_voidSetPinValue('B', 0, LOW);
 GPIO_voidSetPinValue('B', 1, HIGH);
 TIMER0_voidDelayMs(500);
 }
}
