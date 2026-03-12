#include "../HAL/LED/LED_interface.h"
#include "../MCAL/TIMER/TIMER0_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../SERVICES/STD_TYPES.h"

volatile unsigned char led1_counter = 0;
volatile unsigned char led2_counter = 0;

void Timer_Task(){
     if(led1_counter<30){
     Timer0_Reset();
     led1_counter++;

     }
     else if(led1_counter==30){
          Timer0_set(125);
          led1_counter++; }
          else{
               led1_counter=0;
               LED_Toggle(GPIO_PORTB, 0);
               if(led2_counter<2){
               led2_counter++;

               }
               else{
               led2_counter=0;
               LED_Toggle(GPIO_PORTB, 1);

            }


        }
  }
void main(void)
{
    LED_Init(GPIO_PORTB, 0);
    LED_Init(GPIO_PORTB, 1);

    Timer0_initialize();
    Timer0_Enable();
    TMR0_SetCallback(Timer_Task);



    while (1)
    {

    }
}