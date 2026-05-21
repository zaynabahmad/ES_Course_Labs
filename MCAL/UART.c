/**
 * @file    UART.c
 * @brief   USART driver implementation for the PIC16F877A.
 *
 * @details The baud-rate setup is the deliberate part. Textbook drivers pick
 *          one speed mode and apply a single formula. This driver instead
 *          solves *both* the high-speed (BRGH=1, /16) and low-speed (BRGH=0,
 *          /64) divisors with rounding, measures the resulting rate error of
 *          each, and adopts whichever is more accurate while still fitting the
 *          8-bit SPBRG register. The choice is therefore data-driven, not
 *          assumed.
 */
#include "UART_interface.h"
#include "UART_private.h"
#include "UART_cfg.h"
#include "../SERVICES/Macros.h"

/**
 * @brief  Absolute difference of two unsigned values.
 * @note   Written out so the baud solver can compare errors without a
 *         signed cast that the 8-bit toolchain handles awkwardly.
 */
static dword_t u32AbsDiff(dword_t u32A, dword_t u32B)
{
    return (u32A > u32B) ? (u32A - u32B) : (u32B - u32A);
}

/**
 * @brief  Solve and apply the best SPBRG/BRGH pair for UART_BAUD_RATE.
 */
static void vSolveBaud(void)
{
    /* Rounded (divisor + 1) for each mode: add half the denominator before
     * the integer divide so the nearest value is selected, not the floor. */
    dword_t u32HiSpan = (UART_FOSC_HZ + (8uL  * UART_BAUD_RATE)) /
                        (16uL * UART_BAUD_RATE);
    dword_t u32LoSpan = (UART_FOSC_HZ + (32uL * UART_BAUD_RATE)) /
                        (64uL * UART_BAUD_RATE);

    /* Actual baud each span would produce, and how far that lands off target. */
    dword_t u32HiRate = UART_FOSC_HZ / (16uL * u32HiSpan);
    dword_t u32LoRate = UART_FOSC_HZ / (64uL * u32LoSpan);
    dword_t u32HiErr  = u32AbsDiff(u32HiRate, UART_BAUD_RATE);
    dword_t u32LoErr  = u32AbsDiff(u32LoRate, UART_BAUD_RATE);

    /* SPBRG holds span-1. High speed wins only if it fits the register and is
     * no worse than low speed; otherwise fall back to the /64 generator. */
    if (((u32HiSpan - 1uL) <= UART_SPBRG_MAX) && (u32HiErr <= u32LoErr))
    {
        BIT_HIGH(UART_REG_TXSTA, UART_BIT_BRGH);
        UART_REG_SPBRG = (byte_t)(u32HiSpan - 1uL);
    }
    else
    {
        BIT_LOW(UART_REG_TXSTA, UART_BIT_BRGH);
        UART_REG_SPBRG = (byte_t)(u32LoSpan - 1uL);
    }
}

void vUART_Init(void)
{
    /* TX pin is driven by the peripheral but the datasheet still wants the
     * direction bits set as shown: TX output, RX input. */
    BIT_LOW(UART_REG_TRISC, UART_PIN_TX);
    BIT_HIGH(UART_REG_TRISC, UART_PIN_RX);

    BIT_LOW(UART_REG_TXSTA, UART_BIT_SYNC);     /* asynchronous mode. */
    vSolveBaud();                               /* SPBRG + BRGH.      */

    BIT_HIGH(UART_REG_RCSTA, UART_BIT_SPEN);    /* enable the serial port. */
    BIT_HIGH(UART_REG_TXSTA, UART_BIT_TXEN);    /* enable transmitter.     */
    BIT_HIGH(UART_REG_RCSTA, UART_BIT_CREN);    /* enable receiver.        */
}

void vUART_SendByte(byte_t u8Data)
{
    /* Wait for the transmit register to drain before overwriting it. */
    while (BIT_IS_CLEARED(UART_REG_PIR1, UART_BIT_TXIF))
    {
        /* spin */
    }

    UART_REG_TXREG = u8Data;
}

void vUART_SendString(const char *pcText)
{
    if (pcText == NULL_PTR)
    {
        return;
    }

    while (*pcText != '\0')
    {
        vUART_SendByte((byte_t)*pcText);
        pcText++;
    }
}

byte_t u8UART_RecvByte(void)
{
    /* An overrun latches CREN off-by-effect; clearing it re-arms the receiver
     * so a single missed byte does not stall the link forever. */
    if (BIT_IS_RAISED(UART_REG_RCSTA, UART_BIT_OERR))
    {
        BIT_LOW(UART_REG_RCSTA, UART_BIT_CREN);
        BIT_HIGH(UART_REG_RCSTA, UART_BIT_CREN);
    }

    while (BIT_IS_CLEARED(UART_REG_PIR1, UART_BIT_RCIF))
    {
        /* spin */
    }

    return UART_REG_RCREG;
}

flag_t bUART_DataReady(void)
{
    return BIT_IS_RAISED(UART_REG_PIR1, UART_BIT_RCIF) ? FLAG_RAISED
                                                       : FLAG_CLEARED;
}
