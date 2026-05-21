/**
 * @file    Macros.h
 * @brief   Bit / nibble manipulation primitives used by every MCAL driver.
 *
 * @details These wrap the three things register code does constantly -- raise,
 *          clear and test a single bit. They are macros (not functions) so the
 *          compiler folds them into single BSF/BCF/BTFSC instructions; a call
 *          frame here would cost more than the work itself on the 8-bit core.
 *          Names are intentionally verb-led ("HIGH/LOW/PEEK") so the action is
 *          obvious at the call site without checking the definition.
 */
#ifndef MACROS_H
#define MACROS_H

/** @brief Drive bit @p n of @p reg to 1, leaving the other bits untouched. */
#define BIT_HIGH(reg, n)        ( (reg) |=  (1u << (n)) )

/** @brief Drive bit @p n of @p reg to 0, leaving the other bits untouched. */
#define BIT_LOW(reg, n)         ( (reg) &= ~(1u << (n)) )

/** @brief Flip bit @p n of @p reg -- used for LED toggling and edge probes. */
#define BIT_INVERT(reg, n)      ( (reg) ^=  (1u << (n)) )

/** @brief Extract bit @p n of @p reg as a clean 0 or 1. */
#define BIT_PEEK(reg, n)        ( ( (reg) >> (n) ) & 1u )

/** @brief Non-zero when bit @p n is set -- reads naturally in an `if`. */
#define BIT_IS_RAISED(reg, n)   ( BIT_PEEK((reg), (n)) == 1u )

/** @brief Non-zero when bit @p n is clear. */
#define BIT_IS_CLEARED(reg, n)  ( BIT_PEEK((reg), (n)) == 0u )

/** @brief High nibble (bits 7..4) of an 8-bit value, shifted down to 3..0. */
#define NIBBLE_HI(reg)          ( ( (reg) >> 4 ) & 0x0Fu )

/** @brief Low nibble (bits 3..0) of an 8-bit value. */
#define NIBBLE_LO(reg)          ( (reg) & 0x0Fu )

/** @brief Overwrite a whole register in one statement (documents intent). */
#define REG_LOAD(reg, val)      ( (reg) = (val) )

/** @brief Build a 16-bit word from two bytes -- ADC result, timer counts. */
#define WORD_JOIN(hi, lo)       ( ( (word_t)(hi) << 8 ) | (word_t)(lo) )

#endif /* MACROS_H */
