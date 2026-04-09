#ifndef PWM_PRIVATE_H
#define PWM_PRIVATE_H

#define CCP1CON   (*(volatile uint8*)0x17)
#define CCPR1L    (*(volatile uint8*)0x15)
#define PR2       (*(volatile uint8*)0x92)
#define T2CON     (*(volatile uint8*)0x12)
#define PIR1      (*(volatile uint8*)0x0C)

#endif