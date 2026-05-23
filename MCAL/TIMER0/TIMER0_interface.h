#ifndef TIMER0_INTERFACE_H
#define TIMER0_INTERFACE_H

#include "D:\Uni\Y4 S2\Embedded Systems\Final\SERVICES\STD_TYPES.h"

/* Return codes */
#define TIMER0_OK           0u
#define TIMER0_ERR_INVALID  0xFFu

/* ---- Public function prototypes ---- */

void TIMER0_voidInit(void);

void TIMER0_voidDelayMs(unsigned char ms);

void TIMER0_voidSetPreload(unsigned char preload);

void TIMER0_voidEnableInterrupt(void);

void TIMER0_voidDisableInterrupt(void);

void TIMER0_voidClearFlag(void);

unsigned char TIMER0_u8GetFlag(void);

#endif /* TIMER0_INTERFACE_H */