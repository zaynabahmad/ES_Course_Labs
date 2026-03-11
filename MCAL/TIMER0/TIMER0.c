#include "TIMER0.h"
#include "TIMER0_cfg.h"
//static void (*Timer0_Callback)(void) = 0;
//unsigned int overflow_count = 0;
//void TIMER0_Init(void)
//{
//    OPTION_REG = 0b10000111;  // RBPU disabled, prescaler 1:256 to Timer0
//    TMR0 = 0;
//    INTCON.B2 = 0;            // Clear Timer0 overflow flag
//}
//void TIMER0_EnableInterrupt(void)
//{
//    INTCON.B5 = 1;   // Enable Timer0 interrupt (T0IE)
//    INTCON.B7 = 1;   // Global interrupt enable (GIE)
//}
//void TIMER0_SetCallback(void (*ptr)(void))
//{
//    Timer0_Callback = ptr;
//}
//void interrupt()
//{
//    if(INTCON.B2 == 1)        // Timer0 overflow flag (T0IF)
//    {
//        TMR0 = 0;             // Reset timer
//        overflow_count++;
//        if(overflow_count >= 15)  // ~1 second at 4MHz, prescaler 256
//        {
//            overflow_count = 0;
//            if(Timer0_Callback != 0)
//                Timer0_Callback();
//        }
//        INTCON.B2 = 0;        // Clear flag
//    }
//}
// LAB ASSIGNMENT (WEEK3)
#include "TIMER0.h"
static void (*Timer0_Callback)(void) = 0;
void TIMER0_Init(void)
{
    OPTION_REG = 0b10000111;
    TMR0 = 0;
    INTCON.B2 = 0;
}
void TIMER0_EnableInterrupt(void)
{
    INTCON.B5 = 1;
    INTCON.B7 = 1;
}
void TIMER0_SetCallback(void (*ptr)(void))
{
    Timer0_Callback = ptr;
}
void interrupt()
{
    if(INTCON.B2 == 1)
    {
        TMR0 = 6;           // preload instead of 0
        if(Timer0_Callback != 0)
            Timer0_Callback();
        INTCON.B2 = 0;
    }
}
