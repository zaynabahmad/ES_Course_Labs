/**
 * @file    EXTI_cfg.h
 * @brief   Compile-time configuration for the external interrupt (INT0/RB0).
 *
 * @details The PIC16F877A has exactly one external-interrupt source, the INT
 *          pin on RB0. The only board-dependent choice is which edge the wired
 *          signal produces, so that is the single knob exposed here.
 */
#ifndef EXTI_CFG_H
#define EXTI_CFG_H

#include "EXTI_interface.h"

/** Edge applied by vEXTI_Init() before any explicit vEXTI_SetEdge() call. */
#define EXTI_DEFAULT_EDGE       EXTI_EDGE_FALLING

#endif /* EXTI_CFG_H */
