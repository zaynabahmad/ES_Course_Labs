#include "TIMER0.h"
#include "TIMER0_private.h"
#include "../../SERVICES/BIT_MATH.h"

/* Global pointer to hold the application's callback function */
static void (*TIMER0_Callback)(void) = 0;

/* Hardcoded Preload Value for exactly 1ms (Assuming Fosc = 4MHz and Prescaler = 1:8) */
#define TIMER0_PRELOAD_VALUE 131

void TIMER0_Init(void)
{
    /* --- Switch to Memory Bank 1 to access OPTION_REG --- */

    /* Select Internal Clock Source (Fosc/4) -> Clear T0CS */
    CLR_BIT(OPTION_REG, OPTION_REG_T0CS);

    /* Assign Prescaler to Timer0 -> Clear PSA */
    CLR_BIT(OPTION_REG, OPTION_REG_PSA);

    /* Set Prescaler to 1:8 (Bits 2:0 in OPTION_REG to 010) */
    CLR_BIT(OPTION_REG, 0);
    SET_BIT(OPTION_REG, 1);
    CLR_BIT(OPTION_REG, 2);

    /* Load the initial value into Timer0 register */
    TMR0 = TIMER0_PRELOAD_VALUE;

    /* Clear Timer0 Interrupt Flag to avoid false triggers */
    CLR_BIT(INTCON, INTCON_T0IF);
}

void TIMER0_EnableInterrupt(void)
{
    SET_BIT(INTCON, INTCON_T0IE); /* Enable Timer0 interrupt */
    SET_BIT(INTCON, INTCON_GIE);  /* Enable Global Interrupts */
}

void TIMER0_DisableInterrupt(void)
{
    CLR_BIT(INTCON, INTCON_T0IE); /* Disable Timer0 interrupt */
}

void TIMER0_SetCallback(void (*ptr)(void))
{
    if (ptr != 0)
    {
        TIMER0_Callback = ptr;
    }
}

/* =====================================================================
 * INTERRUPT SERVICE ROUTINE (ISR)
 * Note: If using multiple interrupts (like EXT_INT0), they must all share
 * this single 'interrupt' function. You would check both flags here.
//  * ===================================================================== */
void TIMER0_ISR(void)
{
    /* Use a static variable to count milliseconds. It retains its value between interrupts */
    static uint16 ms_counter = 0;

    /* Check if Timer0 Interrupt Flag is triggered */
    if (GET_BIT(INTCON, INTCON_T0IF) == 1)
    {
        /* 1. Clear the flag immediately */
        CLR_BIT(INTCON, INTCON_T0IF);

        /* 2. Reload Timer0 for the next 1ms delay */
        TMR0 = TIMER0_PRELOAD_VALUE;

        /* 3. Increment our hardware-based millisecond counter */
        ms_counter++;

        /* 4. HARDCODED 1-SECOND LOGIC: Check if 1000 ms (1 second) have passed */
        if (ms_counter >= 1000)
        {
            ms_counter = 0; /* Reset the counter for the next second */

            /* Execute the Application Callback (e.g., LED Toggle) */
            if (TIMER0_Callback != 0)
            {
                TIMER0_Callback();
            }
        }
    }
}

// void TIMER0_ISR(void)
// {
//     /* Use a static variable to count milliseconds */
//     static unsigned int ms_counter = 0;

//     /* BYPASS BIT_MATH.h: Directly check if bit 2 (T0IF) is 1 */
//     if (INTCON & (1 << 2))
//     {
//         /* BYPASS BIT_MATH.h: Directly clear bit 2 (T0IF) immediately */
//         INTCON &= ~(1 << 2);

//         /* Reload Timer0 for the next delay */
//         TMR0 = TIMER0_PRELOAD_VALUE;

//         /* Increment our hardware-based millisecond counter */
//         ms_counter++;

//         /* Check if 1000 ms (1 second) have passed */
//         if (ms_counter >= 1000)
//         {
//             ms_counter = 0;

//             /* Execute the Application Callback (LED Toggle) */
//             if (TIMER0_Callback != 0)
//             {
//                 TIMER0_Callback();
//             }
//         }
//     }
// }