#line 1 "C:/Users/OmarT/Downloads/Task3_Interrupt/Interrupt/SERVICES/exti_service.c"
#line 1 "c:/users/omart/downloads/task3_interrupt/interrupt/services/std_types.h"




typedef signed char s8;
typedef signed short int s16;
typedef signed long int s32;


typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;


typedef float f32;
typedef double f64;
typedef long double f128;
#line 1 "c:/users/omart/downloads/task3_interrupt/interrupt/services/../mcal/exti0_interface.h"




void EXTI0_Init(void);
void EXTI0_SetCallback(void (*callback)(void));
#line 1 "c:/users/omart/downloads/task3_interrupt/interrupt/services/../hal/led/led_interface.h"
#line 1 "c:/users/omart/downloads/task3_interrupt/interrupt/services/../hal/led/../../mcal/gpio/gpio_interface.h"
#line 1 "c:/users/omart/downloads/task3_interrupt/interrupt/services/../hal/led/../../mcal/gpio/../../services/std_types.h"
#line 21 "c:/users/omart/downloads/task3_interrupt/interrupt/services/../hal/led/../../mcal/gpio/gpio_interface.h"
void GPIO_SetPinDirection(u8 Port, u8 Pin, u8 Direction);
void GPIO_SetPinValue(u8 Port, u8 Pin, u8 Value);
u8 GPIO_GetPinValue(u8 Port, u8 Pin);
#line 6 "c:/users/omart/downloads/task3_interrupt/interrupt/services/../hal/led/led_interface.h"
void LED_Init(unsigned char port, unsigned char pin);
void LED_Toggle(unsigned char port, unsigned char pin);
#line 6 "C:/Users/OmarT/Downloads/Task3_Interrupt/Interrupt/SERVICES/exti_service.c"
volatile u8 led_toggle_flag = 0;


static void ToggleLED(void) {
 led_toggle_flag = 1;
}


void EXTI0_Service_Init(void) {
 LED_Init(0, 0);
 EXTI0_Init();
 EXTI0_SetCallback(ToggleLED);
}


void EXTI0_Service_Loop(void) {
 if (led_toggle_flag) {
 led_toggle_flag = 0;
 LED_Toggle(0, 0);
 }
}
