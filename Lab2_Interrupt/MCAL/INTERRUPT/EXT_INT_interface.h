#ifndef EXT_INT_INTERFACE_H
#define EXT_INT_INTERFACE_H

#include "../../Services/std_types.h"

/* Interrupt Edge Selection */
#define EXT_INT_RISING_EDGE     1
#define EXT_INT_FALLING_EDGE    0

/* Function Prototypes */
void  EXT_INT0_Init(void);
void  EXT_INT0_Enable(void);
void  EXT_INT0_Disable(void);
void  EXT_INT0_SetEdge(uint8 edge_type);
void  EXT_INT0_ClearFlag(void);
void  EXT_INT0_SetCallback(void (*ptr)(void));

#endif /* EXT_INT_INTERFACE_H */
