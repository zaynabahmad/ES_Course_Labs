#line 1 "D:/Education/TASK 3/APP/main.c"
#line 1 "d:/education/task 3/app/../services/std_types.h"



typedef unsigned char uint8;
typedef unsigned short int uint16;
typedef unsigned long int uint32;
#line 1 "d:/education/task 3/app/../mcal/exti0/exti0_interface.h"



void MEXTI0_vInit(void);
void MEXTI0_vSetCallback(void (*ptr)(void));
#line 1 "d:/education/task 3/app/../hal/led/led_interface.h"



void HLED_vInit(void);
void HLED_vToggle(void);
#line 5 "D:/Education/TASK 3/APP/main.c"
void App_vToggleLogic(void) {
 HLED_vToggle();
}

void main(void) {
 HLED_vInit();
 MEXTI0_vSetCallback(App_vToggleLogic);
 MEXTI0_vInit();

 while(1) {

 }
}
