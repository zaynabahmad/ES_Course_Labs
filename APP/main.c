#include "../HAL/LED/LED_interface.h"
#include "../HAL/SWITCH/SWITCH_interface.h"

#include "../MCAL/GPIO/GPIO_interface.h"

#include "../MCAL/EXTI/EXTI_interface.h"
#include "../MCAL/GIE/GIE_interface.h"


void delay(void)
{
    volatile unsigned int i;
    for(i = 0; i < 50000; i++);
}


void ShortSeq(){
     LED_On(GPIO_PORTB, GPIO_PIN0);
     LED_On(GPIO_PORTB, GPIO_PIN1);
    delay();
    LED_Off(GPIO_PORTB, GPIO_PIN0);
    LED_Off(GPIO_PORTB, GPIO_PIN1);
        delay();
}

void LongSeq(){
     LED_On(GPIO_PORTB, GPIO_PIN0);
     LED_On(GPIO_PORTB, GPIO_PIN1);
     delay();
     delay();
     LED_Off(GPIO_PORTB, GPIO_PIN0);
     LED_Off(GPIO_PORTB, GPIO_PIN1);
         delay();
     delay();
}



// Task 2.1

/* void main(){
     LED_Init(GPIO_PORTB, GPIO_PIN0);
     LED_Init(GPIO_PORTB, GPIO_PIN1);
     
     SWITCH_Init(GPIO_PORTB, GPIO_PIN2);
     SWITCH_Init(GPIO_PORTB, GPIO_PIN3);
     
     while(1){
     if (GetSwitchState(GPIO_PORTB, GPIO_PIN2))
     ShortSeq();
     else if (GetSwitchState(GPIO_PORTB, GPIO_PIN3))
     LongSeq();
     else{
        LED_Off(GPIO_PORTB, GPIO_PIN0);
     LED_Off(GPIO_PORTB, GPIO_PIN1);
     }

     
     }

}
*/




// Task 2.2
void ToggleLED(){
     LED_Toggle(GPIO_PORTB,GPIO_PIN1);
     return;
}

void main (){
     LED_Init(GPIO_PORTB, GPIO_PIN1);
     SWITCH_Init(GPIO_PORTB, GPIO_PIN0);
     
     /* 2. Register the callback */
    EXTI_voidSetCallBack(&ToggleLED);
    EXTI_voidInit();

    /* 3. Enable Global Interrupts (Setting GIE bit in INTCON) */
    GIE_voidEnable();

while(1){
}

}