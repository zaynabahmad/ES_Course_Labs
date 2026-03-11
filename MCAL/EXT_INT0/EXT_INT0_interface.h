#ifndef EXT_INT0_INTERFACE_H
#define EXT_INT0_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"
#include "../GPIO/GPIO_interface.h"

/* INTCON Pin IDs */
#define RBIF 0
#define INTF 1
#define TMR0IF 2
#define RBIE 3
#define INTE 4
#define TMR0IE 5
#define PEIE 6
#define GIE 7

/* OPTION_REG Pin IDs */
#define INTEDG 6
#define INTEDG_RISING 1
#define INTEDG_FALLING 0

void EXT_INT0_Init(void);
void EXT_INT0_Enable(void);
void EXT_INT0_Disable(void);
void EXT_INT0_SetEdge(u8 edge_type);
void EXT_INT0_SetCallback(void (*ptr)(void));

void EXT_INT0_ToggleLED(void);
#endif
