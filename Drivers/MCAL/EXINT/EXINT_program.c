#include "../../SERVICES/BIT_MATH.h"
#include "../../MCAL/EXINT/EXINT_private.h"
#include "../../MCAL/EXINT/EXINT_interface.h"
#include "../../MCAL/EXINT/EXINT_config.h"


static voidCallback_t EXINT_pfuncCallback = NULL;

void EXINT_voidSetCallback(voidCallback_t Copy_Callback) {
    EXINT_pfuncCallback = Copy_Callback;
}

void __interrupt() ISR(void) {
    if(GET_BIT(INTCON, 1)) {  // INTF flag
        CLEAR_BIT(INTCON, 1);
        if(EXINT_pfuncCallback != NULL) {
            EXINT_pfuncCallback();
        }
    }
}

void EXINT_voidInit(void) {
    GPIO_voidSetPinDirection(GPIO_PORTB, GPIO_PIN0, GPIO_PIN_INPUT);
    CLEAR_BIT(INTCON, 1);  // Clear INTF
    CLEAR_BIT(OPTION_REG, 6);  // INTEDG = 0 (falling edge)
    SET_BIT(INTCON, 4);    // INTE = 1
    SET_BIT(INTCON, 7);    // GIE = 1
}