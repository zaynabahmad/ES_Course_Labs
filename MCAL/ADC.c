/**
 * @file    ADC.c
 * @brief   10-bit ADC driver implementation for the PIC16F877A.
 *
 * @details The acquisition wait is the part worth explaining: instead of a
 *          fixed Delay_us(), the driver burns a precise number of instruction
 *          cycles (ADC_ACQ_CYCLES) in a NOP loop. Each NOP is exactly one Tcy,
 *          so the settling time is defined in clock cycles and stays correct
 *          if the core clock is ever rescaled -- only ADC_ACQ_CYCLES moves.
 */
#include "ADC_interface.h"
#include "ADC_private.h"
#include "ADC_cfg.h"
#include "../SERVICES/Macros.h"

/**
 * @brief  Spend exactly ADC_ACQ_CYCLES instruction cycles doing nothing.
 * @note   The loop body is a single NOP, so the burned time is the iteration
 *         count expressed in Tcy units -- a calculated delay, not a guessed one.
 */
static void vAcquisitionWait(void)
{
    word_t u16Cycle;

    for (u16Cycle = 0u; u16Cycle < ADC_ACQ_CYCLES; u16Cycle++)
    {
        asm NOP;
    }
}

void vADC_Init(void)
{
    /* Force every analogue pin to input so the hold capacitor sees the
     * external signal, not a driven latch. Done explicitly rather than
     * trusting the power-on TRIS defaults. */
    ADC_REG_TRISA |= ADC_TRISA_AN_MASK;
    ADC_REG_TRISE |= ADC_TRISE_AN_MASK;

    /* ADCON1: right-justify the result and mark all AN pins analogue. */
    ADC_REG_ADCON1 = ADC_PORTCFG_ALL_AN;
    BIT_HIGH(ADC_REG_ADCON1, ADC_BIT_ADFM);

    /* ADCON0: load the conversion-clock field, channel left at 0, power on. */
    ADC_REG_ADCON0 = (byte_t)(ADC_CLOCK_SELECT << ADC_CLOCK_SHIFT);
    BIT_HIGH(ADC_REG_ADCON0, ADC_BIT_ADON);
}

word_t u16ADC_Capture(eAdcChannel_t eChannel)
{
    if ((byte_t)eChannel > ADC_CHANNEL_MAX)
    {
        return 0u;                      /* reject an out-of-range channel. */
    }

    /* Swap in the requested channel, leaving clock and power bits intact. */
    ADC_REG_ADCON0 = (ADC_REG_ADCON0 &
                      ~(ADC_CHANNEL_MASK << ADC_CHANNEL_SHIFT)) |
                     (byte_t)(((byte_t)eChannel & ADC_CHANNEL_MASK)
                              << ADC_CHANNEL_SHIFT);

    vAcquisitionWait();                 /* let the hold capacitor charge. */

    BIT_HIGH(ADC_REG_ADCON0, ADC_BIT_GODONE);       /* launch conversion. */

    /* GO/DONE self-clears when the result is ready -- poll it down. */
    while (BIT_IS_RAISED(ADC_REG_ADCON0, ADC_BIT_GODONE))
    {
        /* busy-wait: a 10-bit conversion is ~11 Tad, far shorter than any
         * useful yield, so a tight poll is the honest choice here. */
    }

    /* Right-justified: ADRESH carries bits 9:8, ADRESL carries bits 7:0. */
    return WORD_JOIN(ADC_REG_ADRESH & 0x03u, ADC_REG_ADRESL);
}
