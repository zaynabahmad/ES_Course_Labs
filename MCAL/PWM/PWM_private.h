#ifndef PWM_PRIVATE_H
#define PWM_PRIVATE_H

#include "../../SERVICES/Std_Types.h"

/* Timer2 and CCP Registers - using MikroC built-in names */
#define T2CON           (*(volatile unsigned char*)0x12)
#define TMR2            (*(volatile unsigned char*)0x11)
#define PR2             (*(volatile unsigned char*)0x92)

#define CCPR1L          (*(volatile unsigned char*)0x15)
#define CCPR1H          (*(volatile unsigned char*)0x16)
#define CCP1CON         (*(volatile unsigned char*)0x17)

#define CCPR2L          (*(volatile unsigned char*)0x1B)
#define CCPR2H          (*(volatile unsigned char*)0x1C)
#define CCP2CON         (*(volatile unsigned char*)0x1D)

#define TRISC           (*(volatile unsigned char*)0x87)

/* Timer2 Control Bits */
#define T2CKPS0         0   // Prescaler bits
#define T2CKPS1         1
#define TMR2ON          2   // Timer2 Enable

/* CCP Control Bits for PWM Mode */
#define CCP_PWM_MODE    0x0C  // 1100 binary

#endif
