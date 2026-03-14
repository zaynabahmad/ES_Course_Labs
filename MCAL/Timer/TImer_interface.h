#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H

// Define a type for the callback function (takes no args, returns void)
typedef void (*TimerCallback_t)(void);

void Timer0_Init(void);
void Timer0_SetCallback(TimerCallback_t ptr); // Function to "hook" the APP function


#endif