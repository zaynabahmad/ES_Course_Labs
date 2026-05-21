#ifndef TIMER_0_PRIVATE_H
#define TIMER_0_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"

#define TMR0        (*(volatile u8*)0x01)

#ifndef OPTION_REG
#define OPTION_REG  (*(volatile u8*)0x81)
#endif

#ifndef INTCON
#define INTCON      (*(volatile u8*)0x0B)
#endif

#define T0CS_BIT    5
#define T0SE_BIT    4
#define PSA_BIT     3
#define PS_MASK     0x07

#define T0IF_BIT    2
#define T0IE_BIT    5
#define GIE_BIT     7

#define TIMER0_PS_1_2     0x00
#define TIMER0_PS_1_4     0x01
#define TIMER0_PS_1_8     0x02
#define TIMER0_PS_1_16    0x03
#define TIMER0_PS_1_32    0x04
#define TIMER0_PS_1_64    0x05
#define TIMER0_PS_1_128   0x06
#define TIMER0_PS_1_256   0x07

#endif
