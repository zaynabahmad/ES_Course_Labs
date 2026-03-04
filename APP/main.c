//#include "\\Mac\Home\Desktop\Embedded\INT0_Layered\HAL\LED\LED.h"
//#include "C:\Test\Embedded\INT0_Layered\HAL\LED\LED.h"
//#include "C:\Test\Embedded\INT0_Layered\HAL\SWITCH\SWITCH.h."
//#include "C:\Test\Embedded\INT0_Layered\MCAL\EXT_INT\EXT_INT0.h"

//void Toggle_LED()
//{
//    LED_Toggle();
//}

//void main()
//{
//    LED_Init();
//    SWITCH_Init();

//    EXT_INT0_Init();
//    EXT_INT0_SetCallback(Toggle_LED);
//    EXT_INT0_Enable();

//    while(1)
//    {
//         do nothing
//    }
//}

#include "C:\Test\Embedded\INT0_Layered\HAL\LED\LED.h"
#include "C:\Test\Embedded\INT0_Layered\HAL\SWITCH\SWITCH.h"

// EXT_INT0 not used in this task
// #include "C:\Test\Embedded\INT0_Layered\MCAL\EXT_INT\EXT_INT0.h"

void Short_Sequence(void)
{
    LED_On();
    Delay_ms(200);    // 0.2s ON
    LED_Off();
    Delay_ms(200);    // 0.2s OFF
}

void Long_Sequence(void)
{
    LED_On();
    Delay_ms(500);    // 0.5s ON
    LED_Off();
    Delay_ms(500);    // 0.5s OFF
}

void main()
{
    LED_Init();
    SWITCH_Init();

    while(1)
    {
        if(SWITCH1_Read() == 0)
        {
            Short_Sequence();
        }
        else if(SWITCH2_Read() == 0)
        {
            Long_Sequence();
        }
        else
        {
            LED_Off();
        }
    }
}