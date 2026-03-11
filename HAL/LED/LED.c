//#include "LED.h"

//void LED_Init(void)
//{
//    TRISD.B0 = 0;   // RD0 output
//    PORTD.B0 = 0;   // LED OFF
//}

//void LED_Toggle(void)
//{
//    PORTD.B0 = ~PORTD.B0;
//}

// lab task#1 (week 3)
//#include "LED.h"

//void LED_Init(void)
//{
//    TRISB.B0 = 0;   // RB0 as output
//    PORTB.B0 = 0;   // LED OFF initially
//}

//void LED_Toggle(void)
//{
//    PORTB.B0 = !PORTB.B0;  // Logical NOT for clean bit toggle
//}

// LAB ASSIGNMENT (WEEK3)
#include "C:\Test\Embedded\INT0_Layered\MCAL\TIMER0\TIMER0.h"
#include "C:\Test\Embedded\INT0_Layered\MCAL\TIMER0\TIMER0_cfg.h"

#include "LED.h"
void LED_Init(void)
{
    TRISB.B1 = 0;
    TRISB.B0 = 0;   // RB0 not RB2
    PORTB.B1 = 0;
    PORTB.B0 = 0;
}

void LED1_Toggle(void)
{
    PORTB.B0 = !PORTB.B0;
}

void LED2_Toggle(void)
{
    PORTB.B1 = !PORTB.B1;
}
