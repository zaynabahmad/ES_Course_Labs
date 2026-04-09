#ifndef TIMER_0_PRIVATE_H
#define TIMER_0_PRIVATE_H

#include "../../SERVICES/STD_TYPES.h"


#define TMR0_REG            (*(volatile u8*)0x01)
#define INTCON_REG          (*(volatile u8*)0x0B)
#define OPTION_REG          (*(volatile u8*)0x81)
#define T0CS                5
#define T0SE                4
#define PSA                 3


#define PS2                 2
#define PS1                 1
#define PS0                 0


#define PRESCALER_MASK      0xF8



#define GIE                 7
#define T0IE                5
#define T0IF                2



typedef enum {
    TMR0_PRESCALER_2   = 0,         /* 1:2   Prescaler */
    TMR0_PRESCALER_4   = 1,         /* 1:4   Prescaler */
    TMR0_PRESCALER_8   = 2,         /* 1:8   Prescaler */
    TMR0_PRESCALER_16  = 3,         /* 1:16  Prescaler */
    TMR0_PRESCALER_32  = 4,         /* 1:32  Prescaler */
    TMR0_PRESCALER_64  = 5,         /* 1:64  Prescaler */
    TMR0_PRESCALER_128 = 6,         /* 1:128 Prescaler */
    TMR0_PRESCALER_256 = 7          /* 1:256 Prescaler */
} TMR0_Prescaler_t;

#endif /* TIMER_0_PRIVATE_H */