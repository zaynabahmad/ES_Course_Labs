#line 1 "D:/Uni/Y4 S2/Embedded Systems/Final/APP/timer_test.c"
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
#line 1 "d:/uni/y4 s2/embedded systems/final/mcal/timer0/timer0_interface.h"
#line 1 "d:/uni/y4 s2/embedded systems/final/services/std_types.h"
#line 12 "d:/uni/y4 s2/embedded systems/final/mcal/timer0/timer0_interface.h"
void TIMER0_voidInit(void);

void TIMER0_voidDelayMs(unsigned char ms);

void TIMER0_voidSetPreload(unsigned char preload);

void TIMER0_voidEnableInterrupt(void);

void TIMER0_voidDisableInterrupt(void);

void TIMER0_voidClearFlag(void);

unsigned char TIMER0_u8GetFlag(void);
#line 4 "D:/Uni/Y4 S2/Embedded Systems/Final/APP/timer_test.c"
void TIMER_Test(void)
{
 GPIO_voidSetPinDirection('B', 0, OUTPUT);
 GPIO_voidSetPinDirection('B', 1, OUTPUT);

 TIMER0_voidInit();

 while (1)
 {
 GPIO_voidTogglePin('B', 0);
 TIMER0_voidDelayMs(100);

 GPIO_voidTogglePin('B', 1);
 TIMER0_voidDelayMs(100);
 }
}
