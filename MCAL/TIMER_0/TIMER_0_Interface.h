#ifndef TIMER_0_INTERFACE_H
#define TIMER_0_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"
#include "../../SERVICES/BIT_MATH.h"
#include "TIMER_0_Config.h"
#include "TIMER_0_Private.h"

/* ================= Prescaler Macros ================= */

#define TIMER0_PRESCALER_2      0x00
#define TIMER0_PRESCALER_4      0x01
#define TIMER0_PRESCALER_8      0x02
#define TIMER0_PRESCALER_16     0x03
#define TIMER0_PRESCALER_32     0x04
#define TIMER0_PRESCALER_64     0x05
#define TIMER0_PRESCALER_128    0x06
#define TIMER0_PRESCALER_256    0x07

/* ================= Function Prototypes ================= */

void TIMER0_Init(void);
void TIMER0_SetPreload(u8 Preload);
void TIMER0_Start(void);
void TIMER0_Stop(void);
void TIMER0_DelayMs(u16 Ms);
void TIMER0_EnableInterrupt(void);
void TIMER0_DisableInterrupt(void);
void TIMER0_SetCallback(void (*Callback)(void));
void TIMER0_ISR(void);

#endif
