#include "../SERVICES/STD_TYPES.h"
#include "../MCAL/EXT_INT/EXT_INT_Interface.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../HAL/LED/LED_interface.h"
#include "../HAL/SWITCH/SWITCH_interface.h"

#define LED_PORT  GPIO_PORTA
#define LED_PIN   GPIO_PIN0

static u8 led_state = 0;
static u16 interrupt_count = 0;

void Switch_Interrupt_Callback(void)
{
    interrupt_count++;

    led_state = !led_state;
    led_state ? LED_On(LED_PORT, LED_PIN) : LED_Off(LED_PORT, LED_PIN);

    for(u16 i = 0; i < 5000; i++); // debounce
}

void EXT_INT_Test(void)
{
    GPIO_Init();
    LED_Init(LED_PORT, LED_PIN);
    LED_Off(LED_PORT, LED_PIN);
    SWITCH_Init();
    SWITCH_SetCallback(Switch_Interrupt_Callback);
}
