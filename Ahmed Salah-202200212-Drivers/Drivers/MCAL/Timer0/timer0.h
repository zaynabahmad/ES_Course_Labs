/**
 * @file    timer0.h
 * @brief   PIC16F877 Timer0 Driver Header
 * @details Timer0 is an 8-bit timer/counter with configurable prescaler.
 *
 * Key Registers (DS30292C):
 *   TMR0       (0x01) — 8-bit timer register
 *   OPTION_REG (0x81):
 *     bit7  RBPU    — PORTB pull-up (not used here)
 *     bit6  INTEDG  — INT edge (not used here)
 *     bit5  T0CS    — clock source: 0=Fosc/4, 1=T0CKI pin
 *     bit4  T0SE    — T0CKI edge:  0=rising, 1=falling
 *     bit3  PSA     — prescaler assign: 0=Timer0, 1=WDT
 *     bit2-0 PS<2:0>— prescaler rate
 *   INTCON (0x0B):
 *     bit5  T0IE    — Timer0 interrupt enable
 *     bit2  T0IF    — Timer0 overflow flag
 *
 * Prescaler rates when assigned to Timer0 (PSA=0):
 *   PS<2:0>  Divide-by
 *   000       2
 *   001       4
 *   010       8
 *   011      16
 *   100      32
 *   101      64
 *   110     128
 *   111     256
 */

#ifndef TIMER0_H
#define TIMER0_H

#include <pic16f877.h>
#include <stdint.h>

/*============================================================
 * Clock Source
 *============================================================*/
typedef enum {
    TIMER0_CLK_INTERNAL = 0,   /* Fosc/4 — timer mode  */
    TIMER0_CLK_T0CKI    = 1    /* External pin RA4/T0CKI — counter mode */
} TIMER0_ClkSrc_t;

/*============================================================
 * External Clock Edge (T0CKI mode only)
 *============================================================*/
typedef enum {
    TIMER0_EDGE_RISING  = 0,
    TIMER0_EDGE_FALLING = 1
} TIMER0_Edge_t;

/*============================================================
 * Prescaler Assignment
 *============================================================*/
typedef enum {
    TIMER0_PS_ASSIGNED  = 0,   /* Prescaler → Timer0 */
    TIMER0_PS_WDT       = 1    /* Prescaler → WDT    */
} TIMER0_PS_Assign_t;

/*============================================================
 * Prescaler Rate (when PSA = 0)
 *============================================================*/
typedef enum {
    TIMER0_PS_DIV2   = 0x00,
    TIMER0_PS_DIV4   = 0x01,
    TIMER0_PS_DIV8   = 0x02,
    TIMER0_PS_DIV16  = 0x03,
    TIMER0_PS_DIV32  = 0x04,
    TIMER0_PS_DIV64  = 0x05,
    TIMER0_PS_DIV128 = 0x06,
    TIMER0_PS_DIV256 = 0x07
} TIMER0_PS_Rate_t;

/*============================================================
 * Interrupt Enable
 *============================================================*/
typedef enum {
    TIMER0_INT_DISABLE = 0,
    TIMER0_INT_ENABLE  = 1
} TIMER0_Int_t;

/*============================================================
 * Configuration Structure
 *============================================================*/
typedef struct {
    TIMER0_ClkSrc_t   clkSrc;       /* Internal or external clock   */
    TIMER0_Edge_t     extEdge;      /* External edge (T0CKI only)   */
    TIMER0_PS_Assign_t psAssign;    /* Prescaler to Timer0 or WDT   */
    TIMER0_PS_Rate_t  psRate;       /* Prescaler divide ratio        */
    uint8_t           preloadVal;   /* TMR0 preload (0x00-0xFF)      */
    TIMER0_Int_t      intEnable;    /* Enable overflow interrupt     */
} TIMER0_Config_t;

/*============================================================
 * API
 *============================================================*/

/**
 * @brief  Initialize Timer0 with given configuration
 * @param  cfg  Pointer to TIMER0_Config_t
 */
void TIMER0_Init(const TIMER0_Config_t *cfg);

/** @brief  Start Timer0 (loads preload and resumes counting) */
void TIMER0_Start(void);

/** @brief  Stop Timer0 by switching to counter mode on unused edge */
void TIMER0_Stop(void);

/**
 * @brief  Preload TMR0 register (call before each period in ISR)
 * @param  value  0x00–0xFF
 */
void TIMER0_SetPreload(uint8_t value);

/** @brief  Read current TMR0 value */
uint8_t TIMER0_GetCount(void);

/** @brief  Clear Timer0 overflow interrupt flag */
void TIMER0_ClearFlag(void);

/** @brief  Check if overflow flag is set (polling mode) */
uint8_t TIMER0_GetFlag(void);

/** @brief  Enable Timer0 overflow interrupt */
void TIMER0_EnableInterrupt(void);

/** @brief  Disable Timer0 overflow interrupt */
void TIMER0_DisableInterrupt(void);

/**
 * @brief  Blocking delay using Timer0 overflow
 * @param  overflows  Number of TMR0 overflows to wait
 * @note   Assumes GIE=0 (polling mode). For 1 ms at 4MHz Fosc,
 *         preload=6, psRate=DIV8 → each overflow ≈ 1 ms.
 */
void TIMER0_DelayOverflows(uint8_t overflows);

/**
 * @brief  Overflow callback — implement in application
 */
void TIMER0_OVF_Callback(void);

#endif /* TIMER0_H */
