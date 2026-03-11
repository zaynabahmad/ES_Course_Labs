#ifndef _EXT_INT_INTERFACE_H
#define _EXT_INT_INTERFACE_H

#include "../SERVICES/std_types.h"
#include "GPIO/gpio_interface.h"

void EXT_INTO_Init(void);                      /* [cite: 798] */
void EXT_INTO_Enable(void);                    /* [cite: 799] */
void EXT_INTO_SetEdge(u8 edge_type);           /* [cite: 801] */
void EXT_INTO_SetCallback(void (*ptr)(void));  /* [cite: 802] */

#endif