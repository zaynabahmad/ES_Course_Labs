#ifndef PWM_PRIVATE_H
#define PWM_PRIVATE_H

#define CCP1CON (*(volatile unsigned char*)0x17)
#define CCPR1L  (*(volatile unsigned char*)0x15)

#define T2CON   (*(volatile unsigned char*)0x12)
#define PR2     (*(volatile unsigned char*)0x92)

#endif