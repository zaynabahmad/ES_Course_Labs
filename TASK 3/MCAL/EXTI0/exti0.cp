#line 1 "D:/Education/TASK 3/MCAL/EXTI0/exti0.c"
#line 1 "d:/education/task 3/mcal/exti0/../../services/std_types.h"



typedef unsigned char uint8;
typedef unsigned short int uint16;
typedef unsigned long int uint32;
#line 1 "d:/education/task 3/mcal/exti0/../../services/bit_math.h"
#line 1 "d:/education/task 3/mcal/exti0/exti0_interface.h"



void MEXTI0_vInit(void);
void MEXTI0_vSetCallback(void (*ptr)(void));
#line 5 "D:/Education/TASK 3/MCAL/EXTI0/exti0.c"
static void (*G_EXTI0_Callback)(void) = 0;

void MEXTI0_vInit(void) {
 TRISB0_bit = 1;
 INTEDG_bit = 1;
 INTE_bit = 1;
 GIE_bit = 1;
}

void MEXTI0_vSetCallback(void (*ptr)(void)) {
 G_EXTI0_Callback = ptr;
}


void interrupt() {
 if (INTF_bit == 1) {
 if (G_EXTI0_Callback != 0) {
 G_EXTI0_Callback();
 }
 INTF_bit = 0;
 }
}
