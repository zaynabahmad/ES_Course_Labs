#include "TIMER_interface.h"
#include "../../SERVICES/BIT_MATH.h"
#include"../EXTI/EXTI_private.h"

volatile count =0;
volatile sec =0;

void TIMER_INT(void)
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
 
 void TIMER_RESET(void){
count =0;
TMR0=0;
}



static void (*TIMER_Callback)(void) = 0;
static void (*TIMER_Callback2)(void) = 0;

void TIMER_SetCallback(void (*ptr)(void))
{
    TIMER_Callback = ptr;
}
void TIMER_SetCallback2(void (*ptr)(void))
{
    TIMER_Callback2 = ptr;
}






void interrupt()
{

    if(GET_BIT(INTCON, 2))
    {

      CLR_BIT(INTCON,2);
      if(count<30){
       TMR0 =0;
       count++;

      }
      else if(count==30){
      TMR0 =125;
       count++;



      }
      else
      {
          count=0;

          sec ++;
          TIMER_Callback();

          if(sec ==2)
          {
           TIMER_Callback2();
           sec =0;
          }
      
      }
    }
}
