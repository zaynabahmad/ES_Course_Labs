
#ifndef UTIL_H
#define UTIL_H

#define SHORT_TICKER 200
//I made slow ticker alot longer than short ticker as the difference wasnt noticiable otherwise
#define LONG_TICKER 1000

//QUESTION
//I saw that this approach was accepted in other pullrequest so i decided to not waste time implementing something complex 
//but is this actually a proper delay approach ? This delays for the time taken to execute each 
// Delays for a specific number of loop iteration
#define LONGDELAY for(unsigned int i = 0; i < LONG_TICKER; i++){__asm__ volatile("nop");}
#define SHORTDELAY for(unsigned int i = 0; i < SHORT_TICKER; i++){__asm__ volatile("nop");}
//--asm-- key word it meant to make compiler not skip these  








#endif