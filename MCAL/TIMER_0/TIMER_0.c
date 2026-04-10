#include "TIMER_0_interface.h"
#include "../../SERVICES/BIT_MATH.h"
#include"../EXT_INT/EXT_INT_private.h"

volatile count =0;
volatile sec =0;

void TIMER0_INT(void)
{
     SET_BIT(INTCON , 5);
     CLR_BIT(INTCON , 2);
     CLR_BIT(OPTION_REG, 5);
     SET_BIT(INTCON , 7);
     CLR_BIT(OPTION_REG, 3);

     SET_BIT(OPTION_REG, 0);
     SET_BIT(OPTION_REG, 1);
     SET_BIT(OPTION_REG, 2);

     TMR0=0;

 }

 void TIMER0_RESET(void){
      count =0;
      TMR0=0;
}

void (*TIMER_Callback)(void) = 0;

void TIMER0_SetCallback(void (*ptr)(void))
{
    TIMER_Callback = ptr;
}