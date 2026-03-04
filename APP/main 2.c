#include "../HAL/LED/LED.h"
#include "../HAL/Switch/SWITCH.h"
#include "../MCAL/GPIO/GPIO_interface.h"

void main() {

   TRISB.B1 = 0;   // LED1 output
   TRISB.B2 = 0;   // LED2 output

   TRISB.B3 = 1;   // Switch1 input
   TRISB.B4 = 1;   // Switch2 input

   PORTB.B1 = 0;
   PORTB.B2 = 0;

   while(1) {

      // Short sequence (0.2s)
      if(PORTB.B3 == 1) {

         PORTB.B1 = 1;
         PORTB.B2 = 1;
         Delay_ms(200);

         PORTB.B1 = 0;
         PORTB.B2 = 0;
         Delay_ms(200);
      }

      // Long sequence (0.5s)
      else if(PORTB.B4 == 1) {

         PORTB.B1 = 1;
         PORTB.B2 = 1;
         Delay_ms(500);

         PORTB.B1 = 0;
         PORTB.B2 = 0;
         Delay_ms(500);
      }

      // No switch pressed
      else {
         PORTB.B1 = 0;
         PORTB.B2 = 0;
      }
   }
}