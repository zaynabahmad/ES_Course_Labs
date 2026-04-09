#include "../HAL/LED/LED_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/EXT_INT/EXT_INT_interface.h"
#include "../HAL/Switch/Switch_interface.h"
#include "../MCAL/Interrupt Manager/Interrupt_manager.h"
void delay(void)
{
    unsigned int i;
    for(i = 0; i < 50000; i++);
}
// Inside main.c
void MyLogic() { LED_Toggle(GPIO_PORTC, GPIO_PIN0); }

void main()
{
    LED_Init(GPIO_PORTB, GPIO_PIN0);

    while(1)
    LED_Init(GPIO_PORTC, GPIO_PIN0);
    SWITCH_Init(GPIO_PORTB, GPIO_PIN0);
    EXT_INT_Init();
    EXT_INT_SetCallback(MyLogic);
    EXT_INT_Enable();
    while (1)
    {
        LED_On(GPIO_PORTB, GPIO_PIN0);
        delay();

        LED_Off(GPIO_PORTB, GPIO_PIN0);
        delay();
    }
    
}