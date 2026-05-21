/**
 * @file    EXTI_interface.h
 * @brief   Public API of the external interrupt (INT0/RB0) driver.
 */
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

#include "../SERVICES/Types.h"

/** @brief Edge that triggers the interrupt on the INT pin. */
typedef enum
{
    EXTI_EDGE_FALLING = 0,
    EXTI_EDGE_RISING  = 1
} eEdge_t;

/** @brief Signature of a user routine run from interrupt context. */
typedef void (*pfEXTI_Callback_t)(void);

/**
 * @brief  Prepare the INT pin: drive RB0 as input, apply the default edge,
 *         clear any stale flag. Interrupts stay masked until vEXTI_Enable().
 */
void vEXTI_Init(void);

/**
 * @brief  Unmask the external interrupt and the global interrupt enable.
 * @note   Call this only after a callback has been registered.
 */
void vEXTI_Enable(void);

/**
 * @brief  Mask the external interrupt without disturbing other sources.
 */
void vEXTI_Disable(void);

/**
 * @brief  Choose the active edge for the INT pin.
 */
void vEXTI_SetEdge(eEdge_t eEdge);

/**
 * @brief  Register the routine the ISR dispatches to on each valid edge.
 */
void vEXTI_SetCallback(pfEXTI_Callback_t pfCallback);

/**
 * @brief  Per-source interrupt handler -- called by the single global ISR.
 * @note   Checks and clears INTF here so the global ISR stays free of any
 *         register knowledge; does nothing if the flag is not this driver's.
 */
void vEXTI_IsrHandler(void);

#endif /* EXTI_INTERFACE_H */
