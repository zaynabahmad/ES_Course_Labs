#include "EXT_INT_interface.h"
#include "../../Services/bit_math.h"

/* -------------------------------------------------------
 * MCAL - External Interrupt (INT0) Driver
 * Target : PIC16F877A  |  Compiler: mikroC PRO for PIC
 *
 * Registers used:
 *   INTCON  - bit7: GIE  | bit4: INTE  | bit1: INTF
 *   OPTION_REG - bit6: INTEDG  (1=Rising, 0=Falling)
 *   TRISB   - bit0: RB0 direction (must be INPUT)
 * ------------------------------------------------------- */

/* Bit positions inside INTCON */
#define GIE_BIT     7
#define INTE_BIT    4
#define INTF_BIT    1

/* Bit position inside OPTION_REG */
#define INTEDG_BIT  6

/* Private callback pointer - only accessible inside this file */
static void (*EXT_INT0_Callback)(void) = 0;

/* ---- Set the callback function to be called from ISR ---- */
void EXT_INT0_SetCallback(void (*ptr)(void))
{
    EXT_INT0_Callback = ptr;
}

/* ---- Configure RB0 as input, select edge, clear flag ---- */
void EXT_INT0_Init(void)
{
    /* Step 1: Set RB0 as input */
    SET_BIT(TRISB, 0);

    /* Step 2: Default edge = Falling (button press pulls LOW) */
    CLEAR_BIT(OPTION_REG, INTEDG_BIT);

    /* Step 3: Clear interrupt flag before enabling */
    EXT_INT0_ClearFlag();
}

/* ---- Select interrupt trigger edge ---- */
void EXT_INT0_SetEdge(uint8 edge_type)
{
    if(edge_type == EXT_INT_RISING_EDGE)
        SET_BIT(OPTION_REG, INTEDG_BIT);
    else
        CLEAR_BIT(OPTION_REG, INTEDG_BIT);
}

/* ---- Enable INT0 + Global Interrupt ---- */
void EXT_INT0_Enable(void)
{
    SET_BIT(INTCON, INTE_BIT);   /* Enable external interrupt */
    SET_BIT(INTCON, GIE_BIT);    /* Enable global interrupt   */
}

/* ---- Disable INT0 ---- */
void EXT_INT0_Disable(void)
{
    CLEAR_BIT(INTCON, INTE_BIT);
}

/* ---- Clear the interrupt flag (MUST be done inside ISR) ---- */
void EXT_INT0_ClearFlag(void)
{
    CLEAR_BIT(INTCON, INTF_BIT);
}

/* -------------------------------------------------------
 * ISR - Interrupt Service Routine
 * In mikroC PRO: use the 'interrupt' keyword
 * Rules:
 *   - Only clears flag and calls callback
 *   - NO application logic here
 *   - Keep it short and fast
 * ------------------------------------------------------- */
void interrupt(void)
{
    /* Check if it is the External INT0 that fired */
    if(READ_BIT(INTCON, INTF_BIT))
    {
        /* Call the registered callback (application logic lives there) */
        if(EXT_INT0_Callback != 0)
        {
            EXT_INT0_Callback();
        }

        /* IMPORTANT: Always clear the flag inside ISR */
        EXT_INT0_ClearFlag();
    }
}
