                                                                    #ifndef EXT_INT0_H
#define EXT_INT0_H
#define RISING_EDGE  1
#define FALLING_EDGE 0

#include "../Services Layer/Std_Types.h"

void EXT_INT0_Init(void);
void EXT_INT0_Enable(void);
void EXT_INT0_Disable(void);
void EXT_INT0_SetEdge(uint8 edge_type);
void EXT_INT0_SetCallback(void (*ptr)(void));


#endif



