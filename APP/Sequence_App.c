#include "../SERVICES/Std_Types.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/TIMER0/TIMER0_interface.h"
#include "../HAL/LED/LED.h"
#include "../HAL/Switch/Switch.h"


void delay(void){
    unsigned int i;
    for ( i = 0; i < 50000; i++);
}
// Task 1: LED Sequences Controlled by Switches
// You have 2 LEDs and 2 push buttons.
// Switch 1: Short sequence (LEDs blink fast, e.g., 0.2s ON / 0.2s OFF) Switch 2: Long sequence (LEDs blink slow, e.g., 0.5s ON / 0.5s OFF)
// The program continuously checks the switches and runs the sequence of the pressed switch.
// How it works : 1.In the main loop, read the state of Switch 1 and Switch 2. 2.If Switch 1 is pressed --> run the short sequence on the LEDs. 3.If Switch 2 is pressed --> run the long sequence on the LEDs. 4.If no switch is pressed --> turn off the LEDs.

void main() {
    // Main Loop
    LED_Init(GPIO_PORTD, GPIO_PIN0); // LED1
    LED_Init(GPIO_PORTD, GPIO_PIN1); // LED2
    SWITCH_Init(GPIO_PORTB, GPIO_PIN1); // Switch 1
    SWITCH_Init(GPIO_PORTB, GPIO_PIN2); // Switch 2
    while(1){
        
        if(SWITCH_Read(GPIO_PORTB,GPIO_PIN1) == GPIO_LOW){
            LED_On(GPIO_PORTD, GPIO_PIN0);
            LED_On(GPIO_PORTD, GPIO_PIN1);
            Delay_ms(200);
            LED_Off(GPIO_PORTD, GPIO_PIN0);
            LED_Off(GPIO_PORTD, GPIO_PIN1);
            Delay_ms(200);

        }
        else if(SWITCH_Read(GPIO_PORTB,GPIO_PIN2)==GPIO_LOW){
            LED_On(GPIO_PORTD, GPIO_PIN0);
            LED_On(GPIO_PORTD, GPIO_PIN1);
            Delay_ms(500);
            LED_Off(GPIO_PORTD, GPIO_PIN0);
            LED_Off(GPIO_PORTD, GPIO_PIN1);
            Delay_ms(500);

        }
        else{
            LED_Off(GPIO_PORTD, GPIO_PIN0);
            LED_Off(GPIO_PORTD, GPIO_PIN1);
        }
           
    

    }
}
