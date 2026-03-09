#include "TIMER0_interface.h"

static void (*TIMER0_Callback)(void) = 0;
static u8 TIMER0_preload = 6;   

void TIMER0_Init(void)
{
    T0CS_bit = 0;   
    PSA_bit  = 0;   
    PS2_bit  = 0;
    PS1_bit  = 1;
    PS0_bit  = 0;

    TMR0     = TIMER0_preload;
    T0IF_bit = 0;
}

void TIMER0_SetPreload(u8 preload)
{
    TIMER0_preload = preload;
    TMR0 = TIMER0_preload;
}

void TIMER0_EnableInterrupt(void)
{
    T0IF_bit = 0;
    T0IE_bit = 1;
    GIE_bit  = 1;
}

void TIMER0_DisableInterrupt(void)
{
    T0IE_bit = 0;
}

void TIMER0_SetCallback(void (*ptr)(void))
{
    TIMER0_Callback = ptr;
}

void TIMER0_HandleInterrupt(void)
{
    if (T0IF_bit)
    {
        T0IF_bit = 0;
        TMR0     = TIMER0_preload;

        if (TIMER0_Callback != 0)
        {
            TIMER0_Callback();
        }
    }
}