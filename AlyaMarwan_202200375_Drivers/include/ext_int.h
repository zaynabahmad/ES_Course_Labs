#ifndef EXT_INT_H
#define EXT_INT_H

#include "std_types.h"
#include "ext_int_cfg.h"

void EXT_INT_Init(void);
void EXT_INT_Enable(void);
void EXT_INT_Disable(void);
void EXT_INT_ClearFlag(void);
uint8 EXT_INT_GetFlag(void);

#endif