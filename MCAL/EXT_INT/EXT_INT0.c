#include "EXT_INT0.h"
#include "EXT_INT0_private.h"
#include "../GPIO/GPIO_interface.h"
#include "../../SERVICES/BIT_MATH.h"

static void (*INT0_Callback)(void) = 0;

void EXT_INT0_SetEdge(u8 edge_type);

void EXT_INT0_Init(void) {
    GPIO_SetPinDirection(GPIO_PORTB, GPIO_PIN0, GPIO_INPUT); 
    CLR_BIT(INTCON_REG, INTF_BIT);                           
    // Enable PORTB pull-ups (RBPU = 0)
    CLR_BIT(OPTION_REG_CUSTOM, 7);
    EXT_INT0_SetEdge(EXT_INT0_DEFAULT_EDGE); 
}

void EXT_INT0_Enable(void) {
    // 1. Clear the flag to erase any false triggers from setup!
    CLR_BIT(INTCON_REG, INTF_BIT); 
    
    // 2. Enable the interrupt
    SET_BIT(INTCON_REG, INTE_BIT); 
    
    // 3. Enable global interrupts
    SET_BIT(INTCON_REG, GIE_BIT);  
}

void EXT_INT0_Disable(void) {
    CLR_BIT(INTCON_REG, INTE_BIT); 
}

void EXT_INT0_SetEdge(u8 edge_type) {
    if (edge_type == INT0_RISING_EDGE) SET_BIT(OPTION_REG_CUSTOM, INTEDG_BIT);
    else CLR_BIT(OPTION_REG_CUSTOM, INTEDG_BIT);
}

void EXT_INT0_SetCallback(void (*ptr)(void)) {
    INT0_Callback = ptr; 
}

void EXT_INT0_ISR_Handler(void) {
    if (GET_BIT(INTCON_REG, INTF_BIT) == 1) { 
        CLR_BIT(INTCON_REG, INTF_BIT); // Clear flag immediately
        if (INT0_Callback != 0) {
            INT0_Callback(); 
        }
    }
}