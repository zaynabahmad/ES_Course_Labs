#ifndef PWM_PRIVATE_H
#define PWM_PRIVATE_H

#define T2CON       *((volatile u8*)0x12)
#define CCPR1L      *((volatile u8*)0x15)
#define CCP1CON     *((volatile u8*)0x17)
#define PR2         *((volatile u8*)0x92)
#define TMR2ON      2
#define CCP1M3      3
#define CCP1M2      2
#define CCP1X       5
#define CCP1Y       4
#define INTCON      *((volatile u8*)0x0B)
#define OPTION_REG  *((volatile u8*)0x81)
#define TRISB       *((volatile u8*)0x86)
#define TRISC       *((volatile u8*)0x87)
#define GIE         7
#define INTE        4
#define INTF        1
#define INTEDG      6

#endif
