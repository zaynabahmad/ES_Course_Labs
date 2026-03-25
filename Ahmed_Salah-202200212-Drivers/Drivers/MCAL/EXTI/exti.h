/**
 * @file    exti.h
 * @brief   PIC16F877 External Interrupt Driver Header
 * @details Covers:
 *            - INT (RB0/INT) — edge-triggered, INTCON<4:1>
 *            - RB Port Change (RB4:RB7) — INTCON<3,0>
 *
 * Key Registers (DS30292C):
 *   INTCON  (0x0B) — GIE, PEIE, T0IE, INTE, RBIE, T0IF, INTF, RBIF
 *   OPTION_REG (0x81) — INTEDG (bit6): 1=rising, 0=falling
 *
 * Usage:
 *   1. Call EXTI_INT_Init() / EXTI_RBChange_Init()
 *   2. Implement EXTI_INT_Callback() / EXTI_RBChange_Callback() in your code
 *   3. The ISR in exti.c dispatches to the callbacks
 */

#ifndef EXTI_H
#define EXTI_H

#include <pic16f877.h>
#include <stdint.h>

/*============================================================
 * Trigger Edge (for RB0/INT)
 *============================================================*/
typedef enum {
    EXTI_EDGE_FALLING = 0,   /* INTEDG = 0 */
    EXTI_EDGE_RISING  = 1    /* INTEDG = 1 */
} EXTI_Edge_t;

/*============================================================
 * Interrupt Enable / Disable
 *============================================================*/
typedef enum {
    EXTI_DISABLE = 0,
    EXTI_ENABLE  = 1
} EXTI_En_t;

/*============================================================
 * INT (RB0) Configuration
 *============================================================*/
typedef struct {
    EXTI_Edge_t edge;        /* Trigger edge selection        */
    EXTI_En_t   globalIE;    /* Set GIE (INTCON<7>)           */
} EXTI_INT_Config_t;

/*============================================================
 * API — RB0/INT External Interrupt
 *============================================================*/

/**
 * @brief  Initialize RB0/INT external interrupt
 * @param  cfg  Pointer to EXTI_INT_Config_t
 */
void EXTI_INT_Init(const EXTI_INT_Config_t *cfg);

/** @brief  Enable RB0/INT interrupt (INTE bit) */
void EXTI_INT_Enable(void);

/** @brief  Disable RB0/INT interrupt */
void EXTI_INT_Disable(void);

/** @brief  Clear RB0/INT interrupt flag (INTF) — must call in ISR */
void EXTI_INT_ClearFlag(void);

/** @brief  Set trigger edge at runtime */
void EXTI_INT_SetEdge(EXTI_Edge_t edge);

/**
 * @brief  Weak callback — implement in application code
 * @note   Called from ISR; keep it short, no blocking calls
 */
void EXTI_INT_Callback(void);

/*============================================================
 * API — PORTB Change Interrupt (RB4:RB7)
 *============================================================*/

/**
 * @brief  Initialize PORTB change interrupt
 * @param  globalIE  Enable global interrupts after init
 */
void EXTI_RBChange_Init(EXTI_En_t globalIE);

/** @brief  Enable PORTB change interrupt (RBIE bit) */
void EXTI_RBChange_Enable(void);

/** @brief  Disable PORTB change interrupt */
void EXTI_RBChange_Disable(void);

/** @brief  Clear PORTB change flag (RBIF) — must call in ISR */
void EXTI_RBChange_ClearFlag(void);

/**
 * @brief  Weak callback — implement in application code
 * @note   Read PORTB inside callback to end mismatch condition
 */
void EXTI_RBChange_Callback(void);

/*============================================================
 * Global interrupt helpers
 *============================================================*/
/** @brief  Enable global interrupts  (GIE = 1) */
void EXTI_GlobalEnable(void);

/** @brief  Disable global interrupts (GIE = 0) */
void EXTI_GlobalDisable(void);

#endif /* EXTI_H */
