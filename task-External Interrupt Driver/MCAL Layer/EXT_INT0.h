                                                                    #ifndef EXT_INT0_H
#define EXT_INT0_H

#include "../Services Layer/Std_Types.h"

void EXT_INT0_Init(void);
void EXT_INT0_Enable(void);
void EXT_INT0_Disable(void);
void EXT_INT0_SetEdge(uint8 edge_type);
void EXT_INT0_SetCallback(PtrToFunc ptr);

#endif