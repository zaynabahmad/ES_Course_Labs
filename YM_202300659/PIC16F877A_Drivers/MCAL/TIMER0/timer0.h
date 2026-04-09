/*
 * timer0.h
 * MCAL - Timer0 Driver Interface for PIC16F877A
 */

#ifndef TIMER0_H
#define TIMER0_H

typedef unsigned char  u8;
typedef unsigned int   u16;

/* =====================================================
 * Type Definitions
 * ===================================================== */

/* Prescaler Options */
typedef enum {
    TIMER0_PRESCALER_2   = 0x00,
    TIMER0_PRESCALER_4   = 0x01,
    TIMER0_PRESCALER_8   = 0x02,
    TIMER0_PRESCALER_16  = 0x03,
    TIMER0_PRESCALER_32  = 0x04,
    TIMER0_PRESCALER_64  = 0x05,
    TIMER0_PRESCALER_128 = 0x06,
    TIMER0_PRESCALER_256 = 0x07,
    TIMER0_NO_PRESCALER  = 0x08   /* PSA=1: prescaler to WDT (bypass for TMR0) */
} TIMER0_Prescaler_t;

/* Clock Source */
typedef enum {
    TIMER0_CLK_INTERNAL = 0,   /* Fosc/4 */
    TIMER0_CLK_EXTERNAL = 1    /* T0CKI pin (RA4) */
} TIMER0_ClkSrc_t;

/* =====================================================
 * Function Prototypes
 * ===================================================== */

/**
 * @brief  Initialize Timer0 with given prescaler and clock source
 */
void TIMER0_Init(TIMER0_ClkSrc_t clkSrc, TIMER0_Prescaler_t prescaler);

/**
 * @brief  Start Timer0 (enable overflow interrupt)
 */
void TIMER0_Start(void);

/**
 * @brief  Stop Timer0 (disable overflow interrupt)
 */
void TIMER0_Stop(void);

/**
 * @brief  Load a preload value into TMR0 register
 * @param  preload : 8-bit value (0-255)
 */
void TIMER0_SetPreload(u8 preload);

/**
 * @brief  Read current TMR0 counter value
 */
u8 TIMER0_Read(void);

/**
 * @brief  Clear Timer0 overflow interrupt flag
 */
void TIMER0_ClearFlag(void);

/**
 * @brief  Get Timer0 overflow flag
 * @return 1 if overflowed, 0 otherwise
 */
u8 TIMER0_GetFlag(void);

/**
 * @brief  Busy-wait delay in milliseconds (blocking)
 * @param  ms : milliseconds to delay (uses 4MHz Fosc)
 */
void TIMER0_DelayMs(u16 ms);

#endif /* TIMER0_H */
