#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H
#include "STD_TYPES.h"

//I made AI write these 
//Good use of AI !
#define PRESCALER_1_2      2
#define PRESCALER_1_4      4
#define PRESCALER_1_8      8
#define PRESCALER_1_16     16
#define PRESCALER_1_32     32
#define PRESCALER_1_64     64
#define PRESCALER_1_128    128
//Made this value 255 because i was worried about overflow, i think the AI assumed the space of a integer not a u8 variable
#define PRESCALER_1_256    255


#define SELECT_TMR0 0
#define SELECT_TMR2 2



//Returns how much time has elapsed in seconds
u8 time_elapsed(void);

//increments count_ticks
void increment_0_timerTicks(void);

//Returns count_ticks
u32 get_0_timerTicks(void);

//You pass this function a delay time in seconds
void time_delay(u8 time);

//Checks to see if delay time is greater than elapsed time if yes returns true, if not returns false
bool check_delay(void);

//Restarts count of time
void reset_0_timerTicks(void);

//intializes timer, parameters set in config file
void timer_0_intialize(void);

//Set intial value in timer regsiter
void set_timer_0_Reg(void);

//Tackles second being counted correctly issue, this is the only function that should be used to increment 
//the count_ticks
void adjusted_timer_0_second_count(void);

//Currently only used for the MOTOR task, should be used instead for both the intialization of the timer for timer task &
//the motor (Just didnt want to play around with the working code of the timer lol)
void set_timer_0_preScaller(u8);


/*
//You pass this the time you want to check in seconds
//It returns how many times this period of time has passed 
u32 times_timer_elapsed(u8 time);
*/




#endif