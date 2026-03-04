#line 1 "D:/Lab1_Task1/APP/main.c"
#line 1 "d:/lab1_task1/app/../hal/led/led_interface.h"
#line 1 "d:/lab1_task1/app/../hal/led/../../services/std_types.h"



typedef unsigned char uint8;
typedef unsigned int uint16;
typedef unsigned long uint32;
#line 11 "d:/lab1_task1/app/../hal/led/led_interface.h"
void LED_Init(uint8 port, uint8 pin);
void LED_On(uint8 port, uint8 pin);
void LED_Off(uint8 port, uint8 pin);
void LED_Toggle(uint8 port, uint8 pin);
#line 1 "d:/lab1_task1/app/../hal/switch/switch_interface.h"
#line 1 "d:/lab1_task1/app/../hal/switch/../../services/std_types.h"
#line 11 "d:/lab1_task1/app/../hal/switch/switch_interface.h"
void SWITCH_Init(uint8 port, uint8 pin);
uint8 SWITCH_Read(uint8 port, uint8 pin);
#line 1 "d:/lab1_task1/app/../mcal/gpio/gpio_interface.h"
#line 1 "d:/lab1_task1/app/../mcal/gpio/../../services/std_types.h"
#line 32 "d:/lab1_task1/app/../mcal/gpio/gpio_interface.h"
void GPIO_SetPinDirection(uint8 port, uint8 pin, uint8 direction);
void GPIO_WritePin(uint8 port, uint8 pin, uint8 value);
uint8 GPIO_ReadPin(uint8 port, uint8 pin);
#line 43 "D:/Lab1_Task1/APP/main.c"
static void delay_count(unsigned long count)
{
 unsigned long i;
 for(i = 0; i < count; i++)
 {

 }
}

static void blink_leds(unsigned long on_time, unsigned long off_time)
{

 LED_On( 1 ,  0 );
 LED_On( 1 ,  1 );
 delay_count(on_time);


 LED_Off( 1 ,  0 );
 LED_Off( 1 ,  1 );
 delay_count(off_time);
}


void main(void)
{

 LED_Init( 1 ,  0 );
 LED_Init( 1 ,  1 );

 SWITCH_Init( 1 ,  2 );
 SWITCH_Init( 1 ,  3 );


 while(1)
 {
 uint8 sw1_state = SWITCH_Read( 1 ,  2 );
 uint8 sw2_state = SWITCH_Read( 1 ,  3 );

 if(sw1_state ==  0 )
 {

 blink_leds( 40000UL ,  40000UL );
 }
 else if(sw2_state ==  0 )
 {

 blink_leds( 100000UL ,  100000UL );
 }
 else
 {

 LED_Off( 1 ,  0 );
 LED_Off( 1 ,  1 );
 }
 }
}
