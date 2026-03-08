#ifndef TIMER2_PRIVATE_H
#define TIMER2_PRIVATE_H

//TMR for PWM
#define TMR2 (*((volatile u8*)0x11))
//Register for controlling TIMER2
#define T2CON (*((volatile u8*)0x12))
//Register for TIMER 2 period
#define PR2 (*((volatile u8*)0x92))


//Pins for controlling prescale
//(0,0) -> 1 (0,1) -> 4 (1,x) -> 16
#define T2CKPS0 0
#define T2CKPS1 1

//Turning timer on/off bit SET -> on CLR -> off
#define TMR2ON 2

//Pins for controlling postscaler
//0000 -> 1:1 postscale up to 1111 -> 1:16 postscale
#define TOUTPS0 3
#define TOUTPS1 4
#define TOUTPS2 5
#define TOUTPS3 6

#endif