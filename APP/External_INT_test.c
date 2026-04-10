#include "../HAL/LED/LED.h"
#include "../MCAL/EXT_INT/EXT_INT_Interface.h"
#define LED_PIN 1

void Toggle_LED() {
    LED_Toggle(LED_PIN);
}

void main() {
    LED_Init(LED_PIN);   
    LED_Off(LED_PIN);  
     
    EXT_INT0_Init();
    EXT_INT0_SetEdge(RISING_EDGE); 
    EXT_INT0_SetCallback(Toggle_LED);
    EXT_INT0_Enable();

    while(1);
}
#ifndef Delay_ms
  #define Delay_ms(x)  // Dummy macro for GCC syntax check
#endif
#ifndef Delay_us
  #define Delay_us(x)  // Dummy macro for GCC syntax check
#endif