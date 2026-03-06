#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H
#include "STD_TYPES.h"

//Returns how much time has elapsed in seconds
u8 time_elapsed(void);

//increments count_ticks
void increment_timerTicks(void);

//Returns count_ticks
u32 get_timerTicks(void);

//You pass this function a delay time in seconds
void time_delay(u8 time);

//Checks to see if delay time is greater than elapsed time if yes returns true, if not returns false
bool check_delay(void);

//Restarts count of time
void reset_timerTicks(void);

//intializes timer, parameters set in config file
void timer_intialize(void);

//Set intial value in timer regsiter
void set_timerReg(void);

//Tackles second being counted correctly issue, this is the only function that should be used to increment 
//the count_ticks
void adjusted_second_count(void);

/*
//You pass this the time you want to check in seconds
//It returns how many times this period of time has passed 
u32 times_timer_elapsed(u8 time);
*/




#endif