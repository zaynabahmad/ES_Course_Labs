//#include "C:\Test\Embedded\INT0_Layered\HAL\LED\LED.h"
//#include "C:\Test\Embedded\INT0_Layered\HAL\SWITCH\SWITCH.h."
//#include "C:\Test\Embedded\INT0_Layered\MCAL\EXT_INT\EXT_INT0.h"
//void Toggle_LED()
//{
//    LED_Toggle();
//}
//void main()
//{
//    LED_Init();
//    SWITCH_Init();
//    EXT_INT0_Init();
//    EXT_INT0_SetCallback(Toggle_LED);
//    EXT_INT0_Enable();
//    while(1)
//    {
//        // do nothing
//    }
//}
//LAB TASK #1 (WEEK 3)
//#include "C:\Test\Embedded\INT0_Layered\HAL\LED\LED.h"
//#include "C:\Test\Embedded\INT0_Layered\MCAL\TIMER0\TIMER0.h"
//void Toggle_LED()
//{
//    LED_Toggle();
//}
//void main()
//{
//    LED_Init();
//    TIMER0_Init();
//    TIMER0_SetCallback(Toggle_LED);
//    TIMER0_EnableInterrupt();
//    while(1)
//    {
        // nothing
//    }
//}
// LAB ASSIGNMENT (WEEK3)
#include "C:\Test\Embedded\INT0_Layered\HAL\LED\LED.h"
#include "C:\Test\Embedded\INT0_Layered\MCAL\TIMER0\TIMER0.h"
volatile unsigned int counter1 = 0;
volatile unsigned int counter2 = 0;
void Timer_Task()
{
    counter1++;
    counter2++;
    if(counter1 >= 30)
    {
        LED1_Toggle();
        counter1 = 0;
    }
    if(counter2 >= 15)
    {
        LED2_Toggle();
        counter2 = 0;
    }
}
void main()
{
    LED_Init();

    TIMER0_Init();
    TIMER0_SetCallback(Timer_Task);
    TIMER0_EnableInterrupt();
    while(1)
    {
    }
}


