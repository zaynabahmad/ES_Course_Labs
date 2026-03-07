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
#include "../MCAL/External_Interrupt_INT0/EXT_INT0.h"



/*  Task 1

void main()
{
    u8 switch1;
    u8 switch2;
    LED_Init(GPIO_PORTB, GPIO_PIN1);
    LED_Init(GPIO_PORTC, GPIO_PIN0);
    SWITCH_Init(GPIO_PIN0);
    SWITCH_Init(GPIO_PIN1);

    while(1)
    {
        switch1 = SWITCH_STATE(GPIO_PORTB, GPIO_PIN2);
        switch2 = SWITCH_STATE(GPIO_PORTB, GPIO_PIN3);

        if(switch1 && !switch2)
        {
            LED_On(GPIO_PORTB, GPIO_PIN1);
            LED_On(GPIO_PORTC, GPIO_PIN0);
            Delay_ms(100);
            LED_Off(GPIO_PORTB, GPIO_PIN1);
            LED_Off(GPIO_PORTC, GPIO_PIN0);
            Delay_ms(100);
        }
        else if(switch2 && !switch1)
        {
            LED_On(GPIO_PORTB, GPIO_PIN1);
            LED_On(GPIO_PORTC, GPIO_PIN0);
            Delay_ms(500);
            LED_Off(GPIO_PORTB, GPIO_PIN1);
            LED_Off(GPIO_PORTC, GPIO_PIN0);
            Delay_ms(500);
        }
        else
        {
            LED_Off(GPIO_PORTB, GPIO_PIN1);
            LED_Off(GPIO_PORTC, GPIO_PIN0);
        }
    }
    while(1)
    {


        switch1 = GET_BIT(PORTA,1);

        if(switch1)
        {
         LED_On(GPIO_PORTB, GPIO_PIN1);
        Delay_ms(500);

        LED_Off(GPIO_PORTB, GPIO_PIN1);
        Delay_ms(2000);  }
        else{ LED_On(GPIO_PORTB, GPIO_PIN1);}
    } 


}    */
// Task 2
void Interrupt_Task(){
    LED_Toggle(GPIO_PORTC,GPIO_PIN0);

}

void main(){
    LED_Init(GPIO_PORTC, GPIO_PIN0);
    SWITCH_Init(GPIO_PIN0);
    EXT_INT0_Init();
    EXT_INT0_Enable();
    EXT_INT0_SetEdge(0);
    EXT_INT0_SetCallback(Interrupt_Task);
    while(1){
    
    }

}