#include "LED.h"
#include "BUTTON.h"

void main()
{
     ADCON1 = 0x06;  // Disable analog
     OPTION_REG.NOT_RBPU = 0; // Enable pull-ups

     // Initialize LEDs
     LED_Init(&TRISB, 0);  // RB0
     LED_Init(&TRISB, 1);  // RB1

     // Initialize Buttons
     Button_Init(&TRISB, 2);  // RB2
     Button_Init(&TRISB, 3);  // RB3

     while(1)
     {
         // Switch 1 -> Fast
         if(Button_Read(&PORTB, 2) == 0)
         {
              LED_On(&PORTB, 0);
              LED_On(&PORTB, 1);
              Delay_ms(200);

              LED_Off(&PORTB, 0);
              LED_Off(&PORTB, 1);
              Delay_ms(200);
         }

         // Switch 2 -> Slow
         else if(Button_Read(&PORTB, 3) == 0)
         {
              LED_On(&PORTB, 0);
              LED_On(&PORTB, 1);
              Delay_ms(500);

              LED_Off(&PORTB, 0);
              LED_Off(&PORTB, 1);
              Delay_ms(500);
         }

         else
         {
              LED_Off(&PORTB, 0);
              LED_Off(&PORTB, 1);
         }
     }
}