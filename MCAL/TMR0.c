/**
 * @file    TMR0.c
 * @brief   Timer0 driver implementation for the PIC16F877A.
 *
 * @details The prescaler is fixed at compile time, but the preload helper has
 *          to know it both as a PS bit-field (for OPTION_REG) and as a divider
 *          (for the maths). A switch-case translates the configured divider
 *          into both forms, keeping the magic numbers in one readable place.
 */
#include "TMR0_interface.h"
#include "TMR0_private.h"
#include "TMR0_cfg.h"
#include "../SERVICES/Macros.h"

/** Routine invoked on each overflow; NULL_PTR until registered. */
static pfTMR0_Callback_t pfOverflowAction = NULL_PTR;

/**
 * @brief  Map the configured prescaler divider to its 3-bit PS field.
 * @return PS2..PS0 value, or the 1:256 setting if the divider is invalid.
 */
static byte_t u8PrescalerBits(void)
{
    switch (TMR0_PRESCALER_DIV)
    {
        case 2u:   return 0x00u;
        case 4u:   return 0x01u;
        case 8u:   return 0x02u;
        case 16u:  return 0x03u;
        case 32u:  return 0x04u;
        case 64u:  return 0x05u;
        case 128u: return 0x06u;
        case 256u: return 0x07u;
        default:   return 0x07u;        /* safest: slowest count rate. */
    }
}

void vTMR0_Init(void)
{
    /* Internal Fosc/4 clock: T0CS = 0. */
    BIT_LOW(TMR0_REG_OPTION, TMR0_BIT_T0CS);
    /* Route the prescaler to Timer0 (not the WDT): PSA = 0. */
    BIT_LOW(TMR0_REG_OPTION, TMR0_BIT_PSA);

    /* Replace just the PS field, preserving the upper OPTION_REG bits. */
    TMR0_REG_OPTION = (TMR0_REG_OPTION & ~TMR0_MASK_PS) | u8PrescalerBits();

    BIT_LOW(TMR0_REG_INTCON, TMR0_BIT_T0IE);    /* stay stopped for now. */
}

void vTMR0_SetPreload(word_t u16Microseconds)
{
    dword_t u32Ticks;

    /* ticks = us * (Fosc/4 cycles per us) / prescaler. Computed in 32-bit so a
     * large microsecond request cannot overflow before the divide. */
    u32Ticks = ((dword_t)u16Microseconds * TMR0_CYCLES_PER_US);

    switch (TMR0_PRESCALER_DIV)
    {
        case 2u:   u32Ticks >>= 1; break;       /* divide by power-of-two via */
        case 4u:   u32Ticks >>= 2; break;       /* a shift -- no divide call  */
        case 8u:   u32Ticks >>= 3; break;       /* on the 8-bit core.         */
        case 16u:  u32Ticks >>= 4; break;
        case 32u:  u32Ticks >>= 5; break;
        case 64u:  u32Ticks >>= 6; break;
        case 128u: u32Ticks >>= 7; break;
        case 256u: u32Ticks >>= 8; break;
        default:   u32Ticks >>= 8; break;
    }

    /* Clamp: the counter can only be preloaded within its 8-bit span. */
    if (u32Ticks >= TMR0_FULL_SCALE)
    {
        TMR0_REG_COUNT = 0u;                    /* longest possible interval. */
    }
    else
    {
        TMR0_REG_COUNT = (byte_t)(TMR0_FULL_SCALE - u32Ticks);
    }
}

void vTMR0_Start(void)
{
    BIT_LOW(TMR0_REG_INTCON, TMR0_BIT_T0IF);    /* drop a stale overflow. */
    BIT_HIGH(TMR0_REG_INTCON, TMR0_BIT_T0IE);   /* unmask the source.     */
    BIT_HIGH(TMR0_REG_INTCON, TMR0_BIT_GIE);    /* arm the global gate.   */
}

void vTMR0_Stop(void)
{
    BIT_LOW(TMR0_REG_INTCON, TMR0_BIT_T0IE);
}

void vTMR0_SetCallback(pfTMR0_Callback_t pfCallback)
{
    pfOverflowAction = pfCallback;
}

void vTMR0_IsrHandler(void)
{
    if (BIT_IS_RAISED(TMR0_REG_INTCON, TMR0_BIT_T0IE) &&
        BIT_IS_RAISED(TMR0_REG_INTCON, TMR0_BIT_T0IF))
    {
        BIT_LOW(TMR0_REG_INTCON, TMR0_BIT_T0IF);

        if (pfOverflowAction != NULL_PTR)
        {
            pfOverflowAction();
        }
    }
}
