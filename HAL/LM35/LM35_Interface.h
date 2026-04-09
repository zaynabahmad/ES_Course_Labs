#ifndef LM35_INTERFACE_H
#define LM35_INTERFACE_H


#include "../../SERVICES/STD_TYPES.h"


void LM35_Init(void);
u16 LM35_GetTemp(void);
u16 LM35_GetTempTenth(void);

#endif /* LM35_INTERFACE_H */