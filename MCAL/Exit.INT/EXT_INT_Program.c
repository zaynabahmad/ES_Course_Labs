#include "EXT_INT_Interface.h"


static void (*EXTI0_CallBack)(void) = 0;

void EXT_INT0_Init(void)
{
    TRISB0_bit = 1;     
    INTF_bit = 0;       
    INTEDG_bit = 1; //Comment edited 
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


void interrupt()
{
    if (INTF_bit == 1)
    {
        if (EXTI0_CallBack != 0)
        {
            EXTI0_CallBack();
        }
        INTF_bit = 0;   
    }
}