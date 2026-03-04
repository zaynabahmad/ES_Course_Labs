#ifndef INT_INTERFACE_H
#define INT_INTERFACE_H
#include "STD_TYPES.h"


//Interupt task Week 1

//Calls setpin function from GPIO & sets it
void EXT_INTO_Init(void);

//Configure INTEDG
//What this should do is go the the register with the GIE & INTE bits 
//and set each one to 1
void EXT_INTO_Enable(void);

//This functional disables external interrupts (INTE = 0)
void EXT_INTO_Disable(void);

//Sets when the interrupt should be triggered on the rising or falling edge 
void EXT_INTO_SetEdge(u8 edge_type);

//This the function which allows the interrupt to run the function defined
//in the app layer 
void EXT_INTO_SetCallback(void (*ptr)(void));

#endif