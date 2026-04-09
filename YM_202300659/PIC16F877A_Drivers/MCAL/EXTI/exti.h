/*
 * exti.h
 * MCAL - External Interrupt Driver Interface for PIC16F877A
 * Supports INT (RB0) and PORTB change interrupts
 */

#ifndef EXTI_H
#define EXTI_H

typedef unsigned char u8;

/* =====================================================
 * Type Definitions
 * ===================================================== */

typedef enum {
    EXTI_FALLING_EDGE = 0,
    EXTI_RISING_EDGE  = 1
} EXTI_Edge_t;

typedef enum {
    EXTI_INT0    = 0,    /* RB0/INT pin  */
    EXTI_RB_CHG  = 1     /* RB4-RB7 port change */
} EXTI_Source_t;

/* =====================================================
 * Function Prototypes
 * ===================================================== */

/**
 * @brief  Initialize external interrupt on INT0 (RB0)
 * @param  edge : EXTI_RISING_EDGE or EXTI_FALLING_EDGE
 */
void EXTI_Init(EXTI_Edge_t edge);

/**
 * @brief  Enable global + peripheral interrupts and INT0
 */
void EXTI_Enable(EXTI_Source_t src);

/**
 * @brief  Disable INT0 or RB change interrupt
 */
void EXTI_Disable(EXTI_Source_t src);

/**
 * @brief  Enable Global Interrupt (GIE)
 */
void EXTI_GlobalEnable(void);

/**
 * @brief  Disable Global Interrupt (GIE)
 */
void EXTI_GlobalDisable(void);

/**
 * @brief  Clear the INT0 interrupt flag
 */
void EXTI_ClearFlag(EXTI_Source_t src);

/**
 * @brief  Read INT0 interrupt flag
 * @return 1 if flag set, 0 otherwise
 */
u8 EXTI_GetFlag(EXTI_Source_t src);

/**
 * @brief  Set interrupt edge at runtime
 */
void EXTI_SetEdge(EXTI_Edge_t edge);

#endif /* EXTI_H */
