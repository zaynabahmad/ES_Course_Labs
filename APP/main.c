#include "../HAL/LED/LED_interface.h"
#include "../HAL/SWITCH/SWITCH_interface.h"
#include "../MCAL/EXT/EXT_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"

volatile unsigned char toggle_flag = 0;
void Toggle_LED()
{
    toggle_flag = 1;
}
// toggle interrupt
/*void main()
{
    LED_Init(GPIO_PORTC,0);
    SWITCH_Init(GPIO_PORTB,0);

    EXT_INT0_Init();
    EXT_INT0_SetCallback(Toggle_LED);

    while(1)
    {
             if (toggle_flag ==1){
                LED_Toggle(GPIO_PORTC, 0);
                toggle_flag = 0;
             }
    }
}      */


//
void ShortSequence()
{
    LED_On(GPIO_PORTC, 0);
    LED_On(GPIO_PORTC, 1);
    delay_ms(200);

    LED_Off(GPIO_PORTC, 0);
    LED_Off(GPIO_PORTC, 1);
    delay_ms(200);
}


void LongSequence()
{
    LED_On(GPIO_PORTC, 0);
    LED_On(GPIO_PORTC, 1);
    delay_ms(500);

    LED_Off(GPIO_PORTC, 0);
    LED_Off(GPIO_PORTC, 1);
    delay_ms(500);
}

void main()
{

LED_Init(GPIO_PORTC, 0);
LED_Init(GPIO_PORTC, 1);

SWITCH_Init(GPIO_PORTB, 0);
SWITCH_Init(GPIO_PORTB, 1);
while(1)
{
    if(SWITCH_Read(GPIO_PORTB, 0)&&!SWITCH_Read(GPIO_PORTB, 1) )
    {
        ShortSequence();
    }

    else if(SWITCH_Read(GPIO_PORTB, 1)&&!SWITCH_Read(GPIO_PORTB, 0))
    {
        LongSequence();
    }

    else
    {
        LED_Off(GPIO_PORTC, 0);
        LED_Off(GPIO_PORTC, 1);
    }
}
}