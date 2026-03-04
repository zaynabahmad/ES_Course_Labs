 #include "EXT_INT0_interface.h"
 #include "EXT_INT0_private.h"
 
 #include "../GPIO/GPIO_interface.h"
 #include "../../SERVICES/BIT_MATH.h"
 
 static void (*EXT_INT0_Callback)(void) = NULL_PTR;
 
 void EXT_INT0_Init(void)
 {
     /* Configure INT0 pin (RB0) as input */
     GPIO_SetPinDirection(GPIO_PORTB, GPIO_PIN0, GPIO_INPUT);
 
     /* Default edge: falling edge (active-low push button with pull-up) */
     EXT_INT0_SetEdge(EXT_INT0_FALLING_EDGE);
 
     /* Clear INT0 flag */
     CLR_BIT(INTCON, INTF_BIT);
 
     /* Enable INT0 interrupt and global interrupt */
     EXT_INT0_Enable();
 }
 
 void EXT_INT0_Enable(void)
 {
     /* Enable INT0 external interrupt */
     SET_BIT(INTCON, INTE_BIT);
 
     /* Enable global interrupts */
     SET_BIT(INTCON, GIE_BIT);
 }
 
 void EXT_INT0_Disable(void)
 {
     /* Disable INT0 external interrupt */
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
 
 /* ISR implemented in MCAL: calls a callback only (no application logic) */
 void interrupt(void)
 {
     /* Check if INT0 flag is set */
     if(GET_BIT(INTCON, INTF_BIT))
     {
         /* Call application callback if registered */
         if(EXT_INT0_Callback != NULL_PTR)
         {
             EXT_INT0_Callback();
         }
 
         /* Clear INT0 flag */
         CLR_BIT(INTCON, INTF_BIT);
     }
 }
*** End Patch```} />
