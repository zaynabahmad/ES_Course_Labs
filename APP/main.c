#include "../HAL/LED/LED.h"
#include "../MCAL/INT/EXT_interface.h"

#define LED_PIN 1

void Toggle_LED() {
    LED_Toggle(LED_PIN);
}

void main() {
    LED_Init(LED_PIN);   
    LED_Off(LED_PIN);  
     
    EXT_INT0_Init();
    EXT_INT0_SetEdge(EXT_INT0_RISING_EDGE); 
    EXT_INT0_SetCallback(Toggle_LED);
    EXT_INT0_Enable();

    while(1);
}