 #include "EXT_INT0_interface.h"
 #include "EXT_INT0_private.h"
 
 #include "../GPIO/GPIO_interface.h"
 #include "../../SERVICES/BIT_MATH.h"
 
 static void (*EXT_INT0_Callback)(void) = NULL_PTR;
 
 void EXT_INT0_Init(void)
 {
     
     GPIO_SetPinDirection(GPIO_PORTB, GPIO_PIN0, GPIO_INPUT);
 
    CLR_BIT(OPTION_REG, RBPU_BIT);

     EXT_INT0_SetEdge(EXT_INT0_FALLING_EDGE);
 
     CLR_BIT(INTCON, INTF_BIT);
 
     EXT_INT0_Enable();
 }
 
 void EXT_INT0_Enable(void)
 {
     SET_BIT(INTCON, INTE_BIT);
 
     SET_BIT(INTCON, GIE_BIT);
 }
 
 void EXT_INT0_Disable(void)
 {
     CLR_BIT(INTCON, INTE_BIT);
 }
 
 void EXT_INT0_SetEdge(u8 edge_type)
 {
     if(edge_type == EXT_INT0_RISING_EDGE)
     {
         SET_BIT(OPTION_REG, INTEDG_BIT);
     }
     else
     {
         CLR_BIT(OPTION_REG, INTEDG_BIT);
     }
 }
 
 void EXT_INT0_SetCallback(void (*ptr)(void))
 {
     EXT_INT0_Callback = ptr;
 }
 
void interrupt(void)
{
    if(GET_BIT(INTCON, INTF_BIT))
    {
        if(EXT_INT0_Callback != NULL_PTR)
        {
            EXT_INT0_Callback();
        }

        CLR_BIT(INTCON, INTF_BIT);
    }
}
