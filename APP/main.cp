#line 1 "C:/Users/Z B O O K/Downloads/Week2/ES_Course_Labs-main/APP/main.c"
#line 1 "c:/users/z b o o k/downloads/week2/es_course_labs-main/std_types.h"



typedef unsigned char u8;
typedef unsigned int u16;
typedef unsigned long int u32;

typedef signed char s8;
typedef signed int s16;
typedef signed long int s32;

typedef float f32;
typedef double f64;
#line 1 "c:/users/z b o o k/downloads/week2/es_course_labs-main/mcal/gpio/gpio_interface.h"
#line 1 "c:/users/z b o o k/downloads/week2/es_course_labs-main/mcal/gpio/../../services/std_types.h"
#line 31 "c:/users/z b o o k/downloads/week2/es_course_labs-main/mcal/gpio/gpio_interface.h"
void GPIO_SetPinDirection(u8 Port, u8 Pin, u8 Direction);
void GPIO_SetPinValue(u8 Port, u8 Pin, u8 Value);
u8 GPIO_GetPinValue(u8 Port, u8 Pin);
void GPIO_Init(void);
#line 1 "c:/users/z b o o k/downloads/week2/es_course_labs-main/hal/led/led_interface.h"
#line 1 "c:/users/z b o o k/downloads/week2/es_course_labs-main/hal/led/../../services/std_types.h"
#line 10 "c:/users/z b o o k/downloads/week2/es_course_labs-main/hal/led/led_interface.h"
void LED_Init(u8 Port, u8 Pin);
void LED_On(u8 Port, u8 Pin);
void LED_Off(u8 Port, u8 Pin);
void LED_Toggle(u8 Port, u8 Pin);
#line 1 "c:/users/z b o o k/downloads/week2/es_course_labs-main/mcal/timer0/timer0_interface.h"



void TIMER0_voidInit(void);
void TIMER0_voidSetPreload(unsigned char Copy_u8Preload);
void TIMER0_voidEnableInterrupt(void);
void TIMER0_voidSetCallBack(void (*Copy_ptrToFunc)(void));
#line 1 "c:/users/z b o o k/downloads/week2/es_course_labs-main/mcal/gie/gie_interface.h"



void GIE_voidEnable(void);
void GIE_voidDisable(void);
#line 6 "C:/Users/Z B O O K/Downloads/Week2/ES_Course_Labs-main/APP/main.c"
volatile unsigned int TimerCounter = 0;
static unsigned char Led1_State = 0;
static unsigned char Led2_State = 0;


void App_Timer0_Action(void) {
 TimerCounter++;


 if (TimerCounter % 1000 == 0) {
 if (Led2_State == 0) {
 LED_On( 1 ,  2 );
 Led2_State = 1;
 }
 else {
 LED_Off( 1 ,  2 );
 Led2_State = 0;
 }
 }


 if (TimerCounter % 2000 == 0) {
 if (Led1_State == 0) {
 LED_On( 1 ,  1 );
 Led1_State = 1;
 }
 else {
 LED_Off( 1 ,  1 );
 Led1_State = 0;
 }
 }

 if (TimerCounter == 2000) {
 TimerCounter = 0;
 }
}

void main() {

 LED_Init( 1 ,  1 );
 LED_Init( 1 ,  2 );
 TIMER0_voidInit();
 TIMER0_voidSetPreload(6);
 TIMER0_voidSetCallBack(App_Timer0_Action);
 TIMER0_voidEnableInterrupt();
 GIE_voidEnable();
 while (1) {

 }
}
