/*
* APPLICATION LAYER


*/
#define SET_BIT(REG,BIT)      ( (REG) |=  (1U << (BIT)) )
#define CLR_BIT(REG,BIT)      ( (REG) &= ~(1U << (BIT)) )
#define TOG_BIT(REG,BIT)      ( (REG) ^=  (1U << (BIT)) )
#define GET_BIT(REG,BIT)      ( ((REG) >> (BIT)) & 1U )

#include "../HAL/LED/LED_interface.h"
#include "../HAL/Switch/SWITCH_INTERFACE.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/Timer/TIMER_INTERFACE.h"

volatile unsigned char overflow_count=0;
volatile unsigned char overflow_count2=0;



void interrupt_task(){
       if(overflow_count<30){
        Timer0_Reset();
        overflow_count++;

        }
        else if(overflow_count==30){
            Timer0_set(125);
            overflow_count++; }
            else{
            overflow_count=0;
            LED_Toggle(GPIO_PORTB,GPIO_PIN1);
            if(overflow_count2<2){
            overflow_count2++;

            }
            else{
            overflow_count2=0;
            LED_Toggle(GPIO_PORTB,GPIO_PIN2);

            }


        }



  }
void main(){
    LED_Init(GPIO_PORTB, GPIO_PIN1);
    LED_Init(GPIO_PORTB,GPIO_PIN2);
    Timer0_initialize();
    Timer0_Enable();
    TMR0_SetCallback(interrupt_task);
    while(1){
    
    }
    

}