#ifndef BUTTON_INTERFACE_H
#define BUTTON_INTERFACE_H

#include "../../Services/std_types.h"

/* Function Prototypes */
void BUTTON_Init(void);
void BUTTON_SetCallback(void (*ptr)(void));

#endif /* BUTTON_INTERFACE_H */
