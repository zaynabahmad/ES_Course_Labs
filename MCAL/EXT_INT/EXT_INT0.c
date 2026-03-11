#include "EXT_INT0.h"
#include "EXT_INT0_cfg.h"
static void (*INT0_Callback)(void) = 0;
void EXT_INT0_Init(void)
{
    TRISB.B0 = 1;   // RB0 input
    if(INT0_EDGE == 1)
        OPTION_REG.B6 = 1;   // Rising edge
    else
        OPTION_REG.B6 = 0;   // Falling edge
    INTCON.B1 = 0;   // Clear INT0 flag
}
void EXT_INT0_Enable(void)
{
    INTCON.B4 = 1;   // Enable INT0
    INTCON.B7 = 1;   // Enable Global Interrupt
}
void EXT_INT0_SetCallback(void (*ptr)(void))
{
    INT0_Callback = ptr;
}
//void interrupt()
//{
//    if(INTCON.B1 == 1)
//    {
//        if(INT0_Callback != 0)
//        {
//            INT0_Callback();
//        }
//
//        INTCON.B1 = 0;   // Clear flag
//    }
//}
