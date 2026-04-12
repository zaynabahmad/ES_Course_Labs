#include "../SERVICES/STD_TYPES.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../HAL/LED/LED_interface.h"
#include "../HAL/SWITCH/SWITCH_interface.h"

#define GPIO_TEST_PORT   GPIO_PORTA
#define GPIO_TEST_PIN    GPIO_PIN0

void GPIO_Test(void)
{
    /* Initialize GPIO */
    GPIO_Init();

    /* Set test pin as output */
    GPIO_SetPinDirection(GPIO_TEST_PORT, GPIO_TEST_PIN, GPIO_OUTPUT);

    /* Toggle pin to verify GPIO works */
    GPIO_SetPinValue(GPIO_TEST_PORT, GPIO_TEST_PIN, GPIO_HIGH);
    GPIO_SetPinValue(GPIO_TEST_PORT, GPIO_TEST_PIN, GPIO_LOW);
    GPIO_SetPinValue(GPIO_TEST_PORT, GPIO_TEST_PIN, GPIO_HIGH);

    /* Test LED HAL on PORT A PIN 1 */
    LED_Init(GPIO_PORTA, GPIO_PIN1);
    LED_On(GPIO_PORTA, GPIO_PIN1);
    LED_Off(GPIO_PORTA, GPIO_PIN1);
    LED_Toggle(GPIO_PORTA, GPIO_PIN1);

    /* Test SWITCH HAL on PORT B PIN 0 (input; read once) */
    SWITCH_Init(GPIO_PORTB, GPIO_PIN0);
    (void)SWITCH_Read(GPIO_PORTB, GPIO_PIN0);
}
