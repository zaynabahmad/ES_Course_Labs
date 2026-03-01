#line 1 "C:/Users/OmarT/Downloads/Task3_Interrupt/Interrupt/APP/main.c"
#line 1 "c:/users/omart/downloads/task3_interrupt/interrupt/app/../services/exti_service.h"




void EXTI0_Service_Init(void);


void EXTI0_Service_Loop(void);
#line 3 "C:/Users/OmarT/Downloads/Task3_Interrupt/Interrupt/APP/main.c"
void main() {
 EXTI0_Service_Init();

 while(1){
 EXTI0_Service_Loop();
 }
}
