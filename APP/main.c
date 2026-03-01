#include "../SERVICES/STD_TYPES.h"
#include "../HAL/LED/LED_interface.h"
#include "../HAL/BUTTON/Button_interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"

#define MAX_SAMPLES 50
#define TICK_DELAY 1000

void delay(unsigned int num)
{
    /* 'volatile' is necessary here; otherwise mikroC Pro optimizer deletes the loop entirely */
    volatile unsigned int i;
    for(i = 0; i < num; i++);
}

void main()
{
    u8 sequence[MAX_SAMPLES];
    u8 state = 0; /* 0: Idle, 1: Record, 2: Playback */
    u8 sample_index = 0;

    unsigned int blink_counter = 0;
    unsigned int sample_counter = 0;

    /* Initialize Peripherals */
    GPIO_Init();
    LED_Init(GPIO_PORTB, GPIO_PIN0);    /* LED 1: Standard continuous blink */
    LED_Init(GPIO_PORTB, GPIO_PIN1);    /* LED 2: Sequence visualizer */
    Button_Init(GPIO_PORTC, GPIO_PIN0); /* Input Button */

    while(1)
    {
        delay(TICK_DELAY);

        /* --- 1. Normal LED Blinking Logic --- */
        blink_counter++;
        if(blink_counter >= 50)
        {
            LED_Toggle(GPIO_PORTB, GPIO_PIN0);
            blink_counter = 0;
        }

        /* --- 2. Sequence Record & Playback Logic --- */
        if(state == 0) /* IDLE */
        {
            if(Button_GetState(GPIO_PORTC, GPIO_PIN0) == GPIO_HIGH)
            {
                state = 1; /* Trigger start of recording window */
                sample_index = 0;
                sample_counter = 0;
            }
        }
        else if(state == 1) /* RECORDING SEQUENCE */
        {
            sample_counter++;
            if(sample_counter >= 5)
            {
                u8 current_val = Button_GetState(GPIO_PORTC, GPIO_PIN0);
                sequence[sample_index] = current_val;

                /* Show visual feedback of button press during record window */
                if(current_val == GPIO_HIGH)
                    LED_On(GPIO_PORTB, GPIO_PIN1);
                else
                    LED_Off(GPIO_PORTB, GPIO_PIN1);

                sample_index++;
                sample_counter = 0;

                /* Window Limit Reached */
                if(sample_index >= MAX_SAMPLES)
                {
                    state = 2; /* Switch to playback */
                    sample_index = 0;
                    LED_Off(GPIO_PORTB, GPIO_PIN1);

                    /* Very short visual delay so you notice the mode switch */
                    delay(TICK_DELAY * 150);
                }
            }
        }
        else if(state == 2) /* PLAYBACK SEQUENCE */
        {
            sample_counter++;
            if(sample_counter >= 5)
            {
                if(sequence[sample_index] == GPIO_HIGH)
                    LED_On(GPIO_PORTB, GPIO_PIN1);
                else
                    LED_Off(GPIO_PORTB, GPIO_PIN1);

                sample_index++;
                sample_counter = 0;

                /* Playback limit reached, reset to idle */
                if(sample_index >= MAX_SAMPLES)
                {
                    state = 0;
                    LED_Off(GPIO_PORTB, GPIO_PIN1);
                }
            }
        }
    }
}