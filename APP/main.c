#include "../HAL/LED/LED_interface.h"
#include "../HAL/LED/LED_config.h"
#include "../HAL/SWITCH/SWITCH_interface.h"
#include "../HAL/SWITCH/SWITCH_config.h"
#include "../MCAL/EXT_INT/EXT_INT_interface.h"

void ToggleLED_Callback(void)
{
    LED_Toggle(LED1_PORT, LED1_PIN);
}

void main()
{
    LED_Init(LED1_PORT, LED1_PIN);          /* RD0 as output */
    SWITCH_Init(SW1_PORT, SW1_PIN);         /* RB0 as input (HAL)*/

   
    EXT_INT0_Init();                       
    EXT_INT0_SetCallback(ToggleLED_Callback);

    while(1)
    {
        /* CPU idles here; every button press fires INT0
           which calls ToggleLED_Callback via MCAL ISR  */
    }
}
