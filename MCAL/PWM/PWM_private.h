#ifndef PWM_PRIVATE_H
#define PWM_PRIVATE_H


//Register to specific PWM time period
#define PR2 (*((volatile u8*)0x92));



//Side note, Who thought making DIY 10 bit registers by combining some a full register and some bits from another register to be a good idea
//Seems painfuly to deal with :(


//Capture/Compare/PWM Register1 (LSB)
#define CCPR1L (*((volatile u8*)0x15))
//Register contains bit to be combined with CCPR1L bits to make 10 bit for PWM duty cycle
#define CCP1CON (*((volatile u8*)0x17))

//CCPR1L:<5:4>CCP1CON to make a 10 bit register
#define CCP1X 5
#define CCP1Y 4

#define CCP1M0 0
#define CCP1M1 1
#define CCP1M2 2
#define CCP1M3 3

#endif