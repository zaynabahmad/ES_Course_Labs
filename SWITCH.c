 #include "SWITCH_interface.h"
 #include "../../MCAL/GPIO/GPIO_interface.h"
 
 void SWITCH_Init(u8 Pin)
 {
     /* Configure switch pin on PORTB as input */
     GPIO_SetPinDirection(GPIO_PORTB, Pin, GPIO_INPUT);
 }
*** End Patch
