#line 1 "D:/Lab2_Interrupt/APP/main.c"
#line 1 "d:/lab2_interrupt/app/../hal/led/led_interface.h"
#line 1 "d:/lab2_interrupt/app/../hal/led/../../services/std_types.h"



typedef unsigned char uint8;
typedef unsigned int uint16;
typedef unsigned long uint32;
#line 11 "d:/lab2_interrupt/app/../hal/led/led_interface.h"
void LED_Init(uint8 port, uint8 pin);
void LED_On(uint8 port, uint8 pin);
void LED_Off(uint8 port, uint8 pin);
void LED_Toggle(uint8 port, uint8 pin);
#line 1 "d:/lab2_interrupt/app/../hal/button/button_interface.h"
#line 1 "d:/lab2_interrupt/app/../hal/button/../../services/std_types.h"
#line 7 "d:/lab2_interrupt/app/../hal/button/button_interface.h"
void BUTTON_Init(void);
void BUTTON_SetCallback(void (*ptr)(void));
#line 1 "d:/lab2_interrupt/app/../mcal/gpio/gpio_interface.h"
#line 1 "d:/lab2_interrupt/app/../mcal/gpio/../../services/std_types.h"
#line 32 "d:/lab2_interrupt/app/../mcal/gpio/gpio_interface.h"
void GPIO_SetPinDirection(uint8 port, uint8 pin, uint8 direction);
void GPIO_WritePin(uint8 port, uint8 pin, uint8 value);
uint8 GPIO_ReadPin(uint8 port, uint8 pin);
#line 27 "D:/Lab2_Interrupt/APP/main.c"
volatile uint8 g_button_pressed_flag = 0;
#line 34 "D:/Lab2_Interrupt/APP/main.c"
void Button_PressedCallback(void)
{
 g_button_pressed_flag = 1;
}


void main(void)
{

 LED_Init( 2 ,  0 );


 BUTTON_Init();


 BUTTON_SetCallback(Button_PressedCallback);


 while(1)
 {

 if(g_button_pressed_flag == 1)
 {
 g_button_pressed_flag = 0;
 LED_Toggle( 2 ,  0 );
 }
 }
}
