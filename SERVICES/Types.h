/**
 * @file    Types.h
 * @brief   Fixed-width primitive types for the PIC16F877A driver suite.
 *
 * @details mikroC's native int widths are well defined for the 8-bit PIC core,
 *          but raw `unsigned char` / `unsigned int` spread through driver code
 *          hides intent. These aliases pin every variable to an explicit width
 *          so register math (baud divisors, timer preloads) cannot silently
 *          overflow when the code is read or ported.
 */
#ifndef TYPES_H
#define TYPES_H

/* --- Unsigned integers -------------------------------------------------- */
typedef unsigned char   byte_t;     /**< 8-bit  unsigned (0 .. 255)          */
typedef unsigned int    word_t;     /**< 16-bit unsigned (0 .. 65535)        */
typedef unsigned long   dword_t;    /**< 32-bit unsigned                     */

/* --- Signed integers ---------------------------------------------------- */
typedef signed char     sbyte_t;    /**< 8-bit  signed                       */
typedef signed int      sword_t;    /**< 16-bit signed                       */
typedef signed long     sdword_t;   /**< 32-bit signed                       */

/* --- Floating point ----------------------------------------------------- */
typedef float           f32_t;      /**< single-precision float              */

/* --- Boolean -----------------------------------------------------------
 * A distinct type (not an int) so a reader knows the value is two-state and
 * never does arithmetic on it. */
typedef byte_t          flag_t;

/**
 * @brief Logic level passed across the GPIO/HAL boundary.
 *        Kept as an enum so APP code reads `LEVEL_HIGH`, never a bare `1`.
 */
typedef enum
{
    LEVEL_LOW  = 0,
    LEVEL_HIGH = 1
} eLevel_t;

/**
 * @brief Uniform return code for operations that can fail (I2C/SPI/UART).
 *        Callers branch on this instead of inventing per-driver flags.
 */
typedef enum
{
    OUTCOME_OK   = 0,
    OUTCOME_FAIL = 1
} eOutcome_t;

/* Null pointer constant -- named distinctly to avoid clashing with any
 * library `NULL` definition pulled in by mikroC headers. */
#define NULL_PTR    ((void *)0)

/* Convenience boolean literals for `flag_t` values. */
#define FLAG_RAISED     ((flag_t)1)
#define FLAG_CLEARED    ((flag_t)0)

#endif /* TYPES_H */
