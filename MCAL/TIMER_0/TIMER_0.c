#include "TIMER_0_Interface.h"
#include "TIMER_0_Private.h"
#include "TIMER_0_Config.h"

/* Registers (PIC16F877A) */
#define TMR0      *((volatile u8*)0x01)
#define OPTION_REG *((volatile u8*)0x81)
#define INTCON     *((volatile u8*)0x0B)

/* Callback */
void (*TIMER0_Callback)(void) = 0;

/* ============================= */

void TIMER0_Init(void)
{

    /* Mode */
#if TIMER0_MODE == TIMER0_TIMER_MODE
    CLR_BIT(OPTION_REG , T0CS);   // Timer mode
#else
    SET_BIT(OPTION_REG , T0CS);   // Counter mode
#endif

    /* Prescaler assigned to Timer0 */
    CLR_BIT(OPTION_REG , PSA);

    OPTION_REG &= 0b11111000;   // Clear prescaler bits
    OPTION_REG |= TIMER0_PRESCALER;

    /* Enable interrupt */
    SET_BIT(INTCON , T0IE);
    SET_BIT(INTCON , GIE);

}

/* ============================= */

void TIMER0_SetPreload(u8 value)
{
    TMR0 = value;
}

/* ============================= */

void TIMER0_Delay_ms(u16 ms)
{
    u16 i;

    for(i = 0; i < ms; i++)
    {
        TMR0 = 0;

        while(!GET_BIT(INTCON , T0IF));

        SET_BIT(INTCON , T0IF); // Clear flag
    }
}

/* ============================= */

void TIMER0_SetCallback(void (*Copy_ptr)(void))
{
    if(Copy_ptr != 0)
    {
        TIMER0_Callback = Copy_ptr;
    }
}

/* ============================= */

void TIMER0_ISR(void)
{
    if(GET_BIT(INTCON , T0IF))
    {
        SET_BIT(INTCON , T0IF); // Clear flag

        if(TIMER0_Callback != 0)
        {
            TIMER0_Callback();
        }
    }
}