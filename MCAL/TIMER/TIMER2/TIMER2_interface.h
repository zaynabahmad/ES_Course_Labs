#ifndef TIMER2_INTERFACE_H
#define TIMER2_INTERFACE_H
#include "STD_TYPES.h"

//Yes i made AI write this switch case because i wouldnt write all these cases myself
//Good use of AI !
/* ==========================================
   Timer 2 Prescaler Options
   Note: Hardware only supports 1:1, 1:4, and 1:16
   ========================================== */
#define PRESCALER_1_1    1
#define PRESCALER_1_4    4
#define PRESCALER_1_16   16

/* ==========================================
   Timer 2 Postscaler Options
   Note: Hardware supports 1:1 through 1:16
   ========================================== */
#define POSTSCALER_1_1   1
#define POSTSCALER_1_2   2
#define POSTSCALER_1_3   3
#define POSTSCALER_1_4   4
#define POSTSCALER_1_5   5
#define POSTSCALER_1_6   6
#define POSTSCALER_1_7   7
#define POSTSCALER_1_8   8
#define POSTSCALER_1_9   9
#define POSTSCALER_1_10  10
#define POSTSCALER_1_11  11
#define POSTSCALER_1_12  12
#define POSTSCALER_1_13  13
#define POSTSCALER_1_14  14
#define POSTSCALER_1_15  15
#define POSTSCALER_1_16  16

//intializes timer, parameters set in config file
void timer_2_intialize(void);
//Set period regsiter for timer2
void set_period_timer_2_Reg(u8);
//Sets preScaler values, default to 1:16 if input is invalid
void set_timer_2_preScaler(u8);
//Sets postScaler values, default to 1:16 if input is invalid
void set_timer_2_postScaler(u8);
//Returns current setting for postScaler
u8 get_postScaler(void);
//Returns current setting for preScaler
u8 get_preScaler(void);
//Return current value in PR2 register
u8 get_PR2(void);

#endif