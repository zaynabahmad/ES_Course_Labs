#ifndef TIMER0_INTERFACE_H
#define TIMER0_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/* Configuration Options */
#define INTERNAL 0
#define EXTERNAL 1

#define HIGH2LOW 1
#define LOW2HIGH 0

#define PSA_HIGH 1
#define PSA_LOW  0

/* Prescaler values map to the lower 3 bits of OPTION_REG */
#define OPT_2   0b000
#define OPT_4   0b001
#define OPT_8   0b010
#define OPT_16  0b011
#define OPT_32  0b100
#define OPT_64  0b101
#define OPT_128 0b110
#define OPT_256 0b111

/* Function Prototypes */
void TIMER0_Init(void);
void TIMER0_EnableInterrupt(void);
void TIMER0_DisableInterrupt(void);
void TIMER0_SetRegister(u8 val);
u8   TIMER0_GetRegister(void);

void TIMER0_SetCallback(void (*ptr)(void));

/* The ISR handler called by the central Interrupt Manager */
void TMR0_ISR_Handler(void);

#endif