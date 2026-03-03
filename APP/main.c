#include "../HAL/LED/LED_interface.h"
#include "../HAL/SWITCH/SWITCH_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../MCAL/INT0/INT0_interface.h"


// Define  pins
//#define LED1_PORT   GPIO_PORTB
//#define LED1_PIN    GPIO_PIN0

#define LED2_PORT   GPIO_PORTB
#define LED2_PIN    GPIO_PIN1

//#define SW1_PORT    GPIO_PORTB
//#define SW1_PIN     GPIO_PIN2

//#define SW2_PORT    GPIO_PORTB
//#define SW2_PIN     GPIO_PIN3

                                  
void Toggle_LED(void);

void main()
{
      //LAb1_TASK2
 
     INT0_Init();
     LED_Init(LED2_PORT, LED2_PIN);
     INT0_SetCallBack(Toggle_LED);
     while(1)
     {}



 
/*
     //LAb1 TAsk 1
    //  Initialize LEDs
    LED_Init(LED1_PORT, LED1_PIN);
    LED_Init(LED2_PORT, LED2_PIN);

    // Initialize Switches
    // ==========================
    SWITCH_Init(SW1_PORT, SW1_PIN);
    SWITCH_Init(SW2_PORT, SW2_PIN);

    // ==========================
    // 4) Main Loop
    // ==========================
    while(1)
    {
        // Read switches
        u8 sw1 = SWITCH_GetState(SW1_PORT, SW1_PIN);
        u8 sw2 = SWITCH_GetState(SW2_PORT, SW2_PIN);

        // ---------------------------------
        // If Switch 1 pressed -> Fast Blink
        // ---------------------------------
        if(sw1 == SWITCH_PRESSED)
        {
            LED_On(LED1_PORT, LED1_PIN);
            LED_On(LED2_PORT, LED2_PIN);
            Delay_ms(200);

            LED_Off(LED1_PORT, LED1_PIN);
            LED_Off(LED2_PORT, LED2_PIN);
            Delay_ms(200);
        }

        // ---------------------------------
        // If Switch 2 pressed -> Slow Blink
        // ---------------------------------
        else if(sw2 == SWITCH_PRESSED)
        {
            LED_On(LED1_PORT, LED1_PIN);
            LED_On(LED2_PORT, LED2_PIN);
            Delay_ms(500);

            LED_Off(LED1_PORT, LED1_PIN);
            LED_Off(LED2_PORT, LED2_PIN);
            Delay_ms(500);
        }

        // ---------------------------------
        // If No Switch Pressed
        // ---------------------------------
        else
        {
            LED_Off(LED1_PORT, LED1_PIN);
            LED_Off(LED2_PORT, LED2_PIN);
        }
    }
    */
}


void Toggle_LED(void)
{
    LED_Toggle(LED2_PORT, LED2_PIN);
}