#line 1 "D:/Education/TASK 3/SERVICES/exti_service.c"
#line 1 "d:/education/task 3/services/std_types.h"



typedef unsigned char uint8;
typedef unsigned short int uint16;
typedef unsigned long int uint32;
#line 1 "d:/education/task 3/services/bit_math.h"
#line 5 "D:/Education/TASK 3/SERVICES/exti_service.c"
void EXTI_vEnableGlobalInterrupts(void) {

 *((volatile uint8*)0x0B) |= (1 << 7);
}

void EXTI_vDisableGlobalInterrupts(void) {

 *((volatile uint8*)0x0B) &= ~(1 << 7);
}
