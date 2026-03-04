#include <built_in.h>
#include "D:\embeddedsystems\Labs\LABTASK2\Project\HAL\LED\LED.h"
#include "D:\embeddedsystems\Labs\LABTASK2\Project\HAL\SWITCH\SWITCH.h"
#include "D:\embeddedsystems\Labs\LABTASK2\Project\Services\delay.h"

#define LED1 0
#define LED2 1

#define SW1  0
#define SW2  1
void short_sequence()
{
     LED_On(LED1);
     LED_On(LED2);
     delay_ms_custom(200);

     LED_Off(LED1);
     LED_Off(LED2);
     delay_ms_custom(200);
}

void long_sequence()
{
     LED_On(LED1);
     LED_On(LED2);
     delay_ms_custom(500);

     LED_Off(LED1);
     LED_Off(LED2);
     delay_ms_custom(500);
}

void main()
{
     ADCON1 = 0x06;   // Make PORTA digital

     LED_Init();
     SWITCH_Init();

     while(1)
     {
          if(SWITCH_Read(SW1))
          {
               short_sequence();
          }
          else if(SWITCH_Read(SW2))
          {
               long_sequence();
          }
          else
          {
               LED_Off(LED1);
               LED_Off(LED2);
          }
     }
}