#include "EXT_INT0.h"
#include "EXT_INT0_private.h"
#include "../GPIO/GPIO_interface.h"
#include "../../SERVICES/BIT_MATH.h"

static void (*INT0_Callback)(void) = 0;

void EXT_INT0_Init(void) {
    GPIO_SetPinDirection(GPIO_PORTB, GPIO_PIN0, GPIO_INPUT); 
    CLR_BIT(INTCON_REG, INTF_BIT);                           
    EXT_INT0_SetEdge(EXT_INT0_DEFAULT_EDGE); 
}

void EXT_INT0_Enable(void) {
    SET_BIT(INTCON_REG, INTE_BIT); 
    SET_BIT(INTCON_REG, GIE_BIT);  
}

void EXT_INT0_Disable(void) {
    CLR_BIT(INTCON_REG, INTE_BIT); 
}

void EXT_INT0_SetEdge(uint8 edge_type) {
    if (edge_type == INT0_RISING_EDGE) SET_BIT(OPTION_REG_CUSTOM, INTEDG_BIT);
    else CLR_BIT(OPTION_REG_CUSTOM, INTEDG_BIT);
}

void EXT_INT0_SetCallback(void (*ptr)(void)) {
    INT0_Callback = ptr; 
}

void interrupt(void) {
    if (GET_BIT(INTCON_REG, INTF_BIT) == 1) { 
        CLR_BIT(INTCON_REG, INTF_BIT); // Clear flag immediately
        if (INT0_Callback != 0) {
            INT0_Callback(); 
        }
    }
}