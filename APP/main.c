/*
* APPLICATION LAYER


*/
#include "../HAL/LED/LED_interface.h"
#include "../HAL/SWITCH/SWITCH_interface.h"
#include "../MCAL/EXT_INT0/EXT_INT0_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"

void delay(void) {
  unsigned int i;
  for (i = 0; i < 50000; i++)
    ;
}
void ext_interrupt() { EXT_INT0_ToggleLED(); }

void main() {
  /*
   *  Lab task 1
   */
  LED_Init(GPIO_PORTC, GPIO_PIN0);
  LED_Init(GPIO_PORTC, GPIO_PIN1);
  LED_Off(GPIO_PORTC, GPIO_PIN0);
  LED_Off(GPIO_PORTC, GPIO_PIN1);

  SWITCH_Init(GPIO_PORTB, GPIO_PIN0);
  SWITCH_Init(GPIO_PORTB, GPIO_PIN1);

  while (1) {
    if (SWITCH_Read(GPIO_PORTB, GPIO_PIN0)) {
      LED_On(GPIO_PORTC, GPIO_PIN0);
      LED_On(GPIO_PORTC, GPIO_PIN1);
      delay();
      LED_Off(GPIO_PORTC, GPIO_PIN0);
      LED_Off(GPIO_PORTC, GPIO_PIN1);
      delay();

    } else if (SWITCH_Read(GPIO_PORTB, GPIO_PIN1)) {
      LED_On(GPIO_PORTC, GPIO_PIN0);
      LED_On(GPIO_PORTC, GPIO_PIN1);
      delay();
      delay();
      LED_Off(GPIO_PORTC, GPIO_PIN0);
      LED_Off(GPIO_PORTC, GPIO_PIN1);
      delay();
      delay();

    } else {
      LED_Off(GPIO_PORTC, GPIO_PIN0);
      LED_Off(GPIO_PORTC, GPIO_PIN1);
    }
  }

  /*
   *  Lab task 2
   */

  LED_Init(GPIO_PORTC, GPIO_PIN2);
  LED_Off(GPIO_PORTC, GPIO_PIN2);
  SWITCH_Init(GPIO_PORTB, GPIO_PIN0);
  EXT_INT0_Init();
  EXT_INT0_SetCallback(ext_interrupt);
  EXT_INT0_Enable();

  while (1) {
  }

  return;
}
