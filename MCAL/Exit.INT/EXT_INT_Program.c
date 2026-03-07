#include "EXT_INT_Interface.h"
#include "../Timer/Timer_interface.h"


void (*EXTI0_CallBack)(void) = 0;
extern TmrPtr_t TMR0_Callbacks[3];
extern volatile unsigned int cnt, cnt1, cnt2;

void EXT_INT0_Init(void)
{
    TRISB0_bit = 1;     
    INTF_bit = 0;       
    INTEDG_bit = 1;
}

void EXT_INT0_Enable(void)
{
    INTE_bit = 1;       
    GIE_bit  = 1;       
}

void EXT_INT0_Disable(void)
{
    INTE_bit = 0;
}

void EXT_INT0_SetEdge(unsigned char edge_type)
{
    INTEDG_bit = edge_type;
}

void EXT_INT0_SetCallback(void (*ptr)(void))
{
    if (ptr != 0)
    {
        EXTI0_CallBack = ptr;
    }
}



void interrupt() {
    if (TMR0IF_bit) {
        TMR0IF_bit = 0;
        TMR0 = 0;

        cnt++; cnt1++; cnt2++;

        if (cnt >= 31) {
            if (TMR0_Callbacks[0] != 0) TMR0_Callbacks[0]();
            cnt = 0;
        }

        if (cnt1 >= 91) {
           if (TMR0_Callbacks[1] != 0) TMR0_Callbacks[1]();
            cnt1 = 0;
        }

        if (cnt2 >= 61) {
            if (TMR0_Callbacks[2] != 0) TMR0_Callbacks[2]();
            cnt2 = 0;
        }
    }

    if (INTF_bit) {
        if (EXTI0_CallBack != 0) {
            EXTI0_CallBack();
        }
        INTF_bit = 0;
    }
}