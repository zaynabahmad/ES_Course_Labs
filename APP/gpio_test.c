#include "../SERVICES/STD_TYPES.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../HAL/LED/LED_interface.h"

#define LED_TEST_PORT  GPIO_PORTA
#define LED_TEST_PIN   GPIO_PIN0

void GPIO_Test(void)
{
    GPIO_Init();
    LED_Init(LED_TEST_PORT, LED_TEST_PIN);

    LED_On(LED_TEST_PORT, LED_TEST_PIN);
    for(u16 i = 0; i < 10000; i++);

    LED_Off(LED_TEST_PORT, LED_TEST_PIN);
    for(u16 i = 0; i < 10000; i++);
}
