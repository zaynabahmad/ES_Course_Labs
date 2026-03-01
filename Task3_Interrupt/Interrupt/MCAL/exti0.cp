#line 1 "C:/Users/OmarT/Downloads/Task3_Interrupt/Interrupt/MCAL/exti0.c"
#line 1 "c:/users/omart/downloads/task3_interrupt/interrupt/mcal/exti0_interface.h"




void EXTI0_Init(void);
void EXTI0_SetCallback(void (*callback)(void));
#line 5 "C:/Users/OmarT/Downloads/Task3_Interrupt/Interrupt/MCAL/exti0.c"
static void (*EXTI0_Callback)(void) = 0;


void EXTI0_Init(void) {
 TRISB.B0 = 1;
 OPTION_REG.B6 = 0;

 INTCON.B1 = 0;
 INTCON.B4 = 1;
 INTCON.B7 = 1;
}


void EXTI0_SetCallback(void (*callback)(void)) {
 EXTI0_Callback = callback;
}


void interrupt() {
 if (INTCON.B1) {
 if (EXTI0_Callback)
 EXTI0_Callback();

 INTCON.B1 = 0;
 }
}
