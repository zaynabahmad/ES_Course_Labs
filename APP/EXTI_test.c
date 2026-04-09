#include "../SERVICES/std_types.h"
#include "../SERVICES/bit_math.h"
#include "../MCAL/EXTI/EXTI_interface.h"
#include "../MCAL/EXTI/EXTI_private.h"
#include "../HAL/LED/LED_interface.h"

void EXTI_test(void) {
    static u8 Local_u8State = 0;

    LED_voidInit(LED0);
    EXTI_voidInit(EXTI_FALLING_EDGE);
    EXTI_voidEnable();

    /* It will wait for ONE interrupt, toggle the LED, and go back */
    while(GET_BIT(INTCON_REG, 1) == 0);

    if(Local_u8State == 0) {
        LED_voidOn(LED0);
        Local_u8State = 1;
    } else {
        LED_voidOff(LED0);
        Local_u8State = 0;
    }

    CLR_BIT(INTCON_REG, 1); // Clear the flag
}