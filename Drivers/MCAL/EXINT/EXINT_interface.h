#ifndef EXINT_INTERFACE_H
#define EXINT_INTERFACE_H
#include "../../SERVICES/STD_TYPES.h"

typedef void (*voidCallback_t)(void);

void EXINT_voidInit(void);
void EXINT_voidSetCallback(voidCallback_t Copy_Callback);

#endif