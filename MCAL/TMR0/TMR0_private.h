#ifndef TMR0_PRIVATE_H
#define TMR0_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

#define TMR0        (*(volatile u8*)0x01)
#define OPTION_REG  (*(volatile u8*)0x81)
#define OPTION_T0CS  5
#define OPTION_PSA   3
#define OPTION_PS2   2
#define OPTION_PS1   1
#define OPTION_PS0   0

#define INTCON      (*(volatile u8*)0x0B)
#define INTCON_GIE   7
#define INTCON_T0IE  5
#define INTCON_T0IF  2

/* 8MHz, Prescaler 1:256, ~10ms tick */
#define TMR0_PRELOAD    131u

#endif