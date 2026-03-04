#line 1 "D:/Lab2_Interrupt/HAL/BUTTON/BUTTON_program.c"
#line 1 "d:/lab2_interrupt/hal/button/button_interface.h"
#line 1 "d:/lab2_interrupt/hal/button/../../services/std_types.h"



typedef unsigned char uint8;
typedef unsigned int uint16;
typedef unsigned long uint32;
#line 7 "d:/lab2_interrupt/hal/button/button_interface.h"
void BUTTON_Init(void);
void BUTTON_SetCallback(void (*ptr)(void));
#line 1 "d:/lab2_interrupt/hal/button/../../mcal/interrupt/ext_int_interface.h"
#line 1 "d:/lab2_interrupt/hal/button/../../mcal/interrupt/../../services/std_types.h"
#line 11 "d:/lab2_interrupt/hal/button/../../mcal/interrupt/ext_int_interface.h"
void EXT_INT0_Init(void);
void EXT_INT0_Enable(void);
void EXT_INT0_Disable(void);
void EXT_INT0_SetEdge(uint8 edge_type);
void EXT_INT0_ClearFlag(void);
void EXT_INT0_SetCallback(void (*ptr)(void));
#line 10 "D:/Lab2_Interrupt/HAL/BUTTON/BUTTON_program.c"
void BUTTON_Init(void)
{
 EXT_INT0_Init();
 EXT_INT0_SetEdge( 0 );
 EXT_INT0_Enable();
}

void BUTTON_SetCallback(void (*ptr)(void))
{
 EXT_INT0_SetCallback(ptr);
}
