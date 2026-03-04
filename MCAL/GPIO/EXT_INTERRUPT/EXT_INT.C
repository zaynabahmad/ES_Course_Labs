#include "EXT_INT_INTERFACE.h"
#include "EXT_INT_config.h"
#include "EXT_INT_PRIVATE.h"
#include "../GPIO/GPIO_interface.h"
#include "../../SERVICES/BIT_MATH.h"

void EXT_INT_Init(void)
{
    // Configure the edge type for the external interrupt
    EXT_INT_SetEdge(falling_edge); // Default to falling edge, can be changed later

    // Configure the external interrupt pin as input 
    GPIO_SetPinDirection(EXT_INT_PORT, EXT_INT_PIN, GPIO_INPUT);
    
    // Clear the interrupt flag
    CLR_BIT(INTCON, INTF_BIT);
    CLR_BIT(INTCON, INTE_BIT); 
}

void EXT_INT_Enable(void)
{
    // Enable the external interrupt
    SET_BIT(INTCON, INTE_BIT);
    
    // Enable global interrupts
    SET_BIT(INTCON, GIE_BIT);

    CLR_BIT(INTCON, INTF_BIT); // Clear any pending interrupt flag
}

void EXT_INT_Disable(void)
{
    // Clear the interrupt flag
    CLR_BIT(INTCON, INTF_BIT);
    // Disable the external interrupt
    CLR_BIT(INTCON, INTE_BIT);
    
}

void EXT_INT_SetEdge(u8 Edgetype)
{
    if (Edgetype == rising_edge)
    {
        // Rising edge
        CLR_BIT(OPTION_REG, INTEDGE_BIT); // 0 for rising
    }
    else if (Edgetype == falling_edge)
    {
        // Falling edge
        SET_BIT(OPTION_REG, INTEDGE_BIT); // 1 for falling
    }
}

static void (*EXT_INT_Callback)(void) = 0;

void EXT_INT_SetCallback(void (*ptr)(void)) {
    if (ptr != 0) {
        EXT_INT_Callback = ptr;
    }
}

void interrupt() {
    if (GET_BIT(INTCON, INTF_BIT)) {
        // clear the interrupt flag
        CLR_BIT(INTCON, INTF_BIT);
        
        // call the registered callback function
        if (EXT_INT_Callback != 0) {
            EXT_INT_Callback();
        }
    }
}