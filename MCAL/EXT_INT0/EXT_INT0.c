#include "STD_TYPES.h"
#include "EXT_INT0_interface.h"
#include "EXT_INT0_config.h"

/* Static callback pointer */
static void (*EXT_INT0_Callback)(void) = NULL_PTR;

/* Initialize INT0 */
void EXT_INT0_Init(void)
{
    /* RB0 as input */
    TRISB.B0 = 1;

    /* Edge Selection */
#if EXT_INT0_EDGE == EXT_INT0_RISING_EDGE
    OPTION_REG.B6 = 1;   // Rising edge
#else
    OPTION_REG.B6 = 0;   // Falling edge
#endif

    /* Clear interrupt flag */
    INTCON.B1 = 0;   // INTF
}

/* Enable INT0 */
void EXT_INT0_Enable(void)
{
    INTCON.B4 = 1;   // INTE
    INTCON.B7 = 1;   // GIE
}

/* Disable INT0 */
void EXT_INT0_Disable(void)
{
    INTCON.B4 = 0;   // INTE
}

/* Change edge at runtime */
void EXT_INT0_SetEdge(u8 Copy_u8Edge)
{
    if(Copy_u8Edge == EXT_INT0_RISING_EDGE)
        OPTION_REG.B6 = 1;
    else
        OPTION_REG.B6 = 0;
}

/* Set callback function */
void EXT_INT0_SetCallback(void (*Copy_ptr)(void))
{
    EXT_INT0_Callback = Copy_ptr;
}

/* ISR (mikroC syntax) */
void interrupt()
{
    if(INTCON.B1)   // Check INTF
    {
        if(EXT_INT0_Callback != NULL_PTR)
        {
            EXT_INT0_Callback();
        }

        INTCON.B1 = 0;   // Clear INTF
    }
}