#include "EXTI_interface.h"
#include "EXTI_private.h"
 
 
#include "../../SERVICES/BIT_MATH.h"
#include "../TIMER/TIMER_interface.h"





void EXT_INT0_Init(void)
{
    SET_BIT(TRISB, 0);

    
    CLR_BIT(INTCON, 1); // INTF
    CLR_BIT(INTCON, 4); // INTE
    SET_BIT(INTCON, 7); // GIE
    SET_BIT(OPTION_REG, 6);   // INTEGD -> Falling




}

void EXT_INT0_Enable(void)
{
    CLR_BIT(INTCON, 1); // INTF
    SET_BIT(INTCON, 4); // INTE
}

void EXT_INT0_Disable(void)
{
    CLR_BIT(INTCON, 4);
}

void EXT_INT0_SetEdge(u8 edge_type)
{
    if(edge_type == RISING_EDGE) {
        SET_BIT(OPTION_REG, 6);   // INTEGD -> Rising
    } else {
        CLR_BIT(OPTION_REG, 6);   // INTEGD -> Falling
    }
}




/* static void (*EXT_INT0_Callback)(void) = 0;

void EXT_INT0_SetCallback(void (*ptr)(void))
{
    EXT_INT0_Callback = ptr;
}
static void (*TIMER_Callback)(void) = 0;

void TIMER_SetCallback(void (*ptr)(void))
{
    TIMER_Callback = ptr;
}


volatile count =0;
volatile sec =0;
volatile ext_counter=0;
void interrupt()
{
    if(GET_BIT(INTCON, 1)) {
        CLR_BIT(INTCON, 1);
        ext_counter ++;

        if(ext_counter >=4) {
            EXT_INT0_Callback();
        }
    }
    if(GET_BIT(INTCON, 2))
    {
      CLR_BIT(INTCON,2);
      if(count<30){
       TMR0 =0;
       count++;

      }
      else{
      TMR0 =125;
      count=0;
      sec ++;
      if(sec ==2){
       TIMER_Callback();
       sec =0;
       }
      }
    }
}
*/
