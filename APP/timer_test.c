#include "../SERVICES/STD_TYPES.h"
#include "../MCAL/TIMER_0/TIMER_0_Interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../HAL/LED/LED_interface.h"

#define LED1_PORT  GPIO_PORTA
#define LED1_PIN   GPIO_PIN0
#define LED2_PORT  GPIO_PORTB
#define LED2_PIN   GPIO_PIN1

static u16 timer_count = 0;
static u8 led1_state = 0;
static u8 led2_state = 0;

void Timer0_Interrupt_Callback(void)
{
    timer_count++;

    if(timer_count % 100 == 0) { // LED1 slower frequency
        led1_state = !led1_state;
        led1_state ? LED_On(LED1_PORT, LED1_PIN) : LED_Off(LED1_PORT, LED1_PIN);
    }

    if(timer_count % 50 == 0) { // LED2 faster frequency
        led2_state = !led2_state;
        led2_state ? LED_On(LED2_PORT, LED2_PIN) : LED_Off(LED2_PORT, LED2_PIN);
    }

    if(timer_count >= 10000) timer_count = 0;
}

void TIMER_0_Test(void)
{
    GPIO_Init();
    LED_Init(LED1_PORT, LED1_PIN);
    LED_Init(LED2_PORT, LED2_PIN);
    TIMER_0_Init();
    TIMER_0_SetCallback(Timer0_Interrupt_Callback);
    TIMER_0_Enable();
}
