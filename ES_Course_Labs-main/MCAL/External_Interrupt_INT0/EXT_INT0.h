#include "../../MCAL/GPIO/GPIO_interface.h"
#include "../../SERVICES/BIT_MATH.h"


void EXT_INT0_Init(void);
void EXT_INT0_Enable(void);
void EXT_INT0_Disable(void);
void EXT_INT0_SetEdge(u8 edge_type);
void EXT_INT0_SetCallback(void (*ptr)(void));
u8 Int_get_flag();
void Int_set_flag();
void Int_clr_flag();