#include "D:\Uni\Y4 S2\Embedded Systems\Final\SERVICES\STD_TYPES.h"
#include "D:\Uni\Y4 S2\Embedded Systems\Final\SERVICES\BIT_MATH.h"
#include "D:\Uni\Y4 S2\Embedded Systems\Final\MCAL\TIMER0\TIMER0_private.h"
#include "D:\Uni\Y4 S2\Embedded Systems\Final\MCAL\TIMER0\TIMER0_interface.h"

/* ---------------------------------------------------------- */
void TIMER0_voidInit(void)
{

    CLR_BIT(OPTION_REG, OPTION_T0CS);

    CLR_BIT(OPTION_REG, OPTION_PSA);

    OPTION_REG &= ~(0x07u);                        /* clear PS2:PS0 */
    OPTION_REG |= TIMER0_PRESCALE_1MS;             /* set 1:8       */


    TMR0 = TIMER0_PRELOAD_1MS;


    CLR_BIT(INTCON, INTCON_T0IF);
}

/* ---------------------------------------------------------- */
void TIMER0_voidDelayMs(unsigned char ms)
{
    unsigned char i;


    for (i = 0u; i < ms; i++)
    {
    
        TMR0 = TIMER0_PRELOAD_1MS;


        CLR_BIT(INTCON, INTCON_T0IF);


        while (GET_BIT(INTCON, INTCON_T0IF) == 0u)
        {
            /* spin */
        }
    }

    /* Clear flag after the last iteration */
    CLR_BIT(INTCON, INTCON_T0IF);
}

/* ---------------------------------------------------------- */
void TIMER0_voidSetPreload(unsigned char preload)
{

    TMR0 = preload;
}

/* ---------------------------------------------------------- */
void TIMER0_voidEnableInterrupt(void)
{
    /* Clear the flag first to avoid an immediate false trigger */
    CLR_BIT(INTCON, INTCON_T0IF);

    /* Enable Timer0 overflow interrupt */
    SET_BIT(INTCON, INTCON_T0IE);

    /* Enable global interrupts — nothing fires without this */
    SET_BIT(INTCON, INTCON_GIE);
}

/* ---------------------------------------------------------- */
void TIMER0_voidDisableInterrupt(void)
{

    CLR_BIT(INTCON, INTCON_T0IE);
}

/* ---------------------------------------------------------- */
void TIMER0_voidClearFlag(void)
{

    CLR_BIT(INTCON, INTCON_T0IF);
}

/* ---------------------------------------------------------- */
unsigned char TIMER0_u8GetFlag(void)
{
    return GET_BIT(INTCON, INTCON_T0IF);
}