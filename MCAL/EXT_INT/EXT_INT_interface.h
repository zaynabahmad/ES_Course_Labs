#ifndef EXT_INT_INTERFACE_H
#define EXT_INT_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"
#include "../GPIO/GPIO_interface.h"


/* Port IDs */
#define GPIO_PORTA   0
#define GPIO_PORTB   1
#define GPIO_PORTC   2
#define GPIO_PORTD   3
#define GPIO_PORTE   4

/* Pin IDs */
#define GPIO_PIN0    0
#define GPIO_PIN1    1
#define GPIO_PIN2    2
#define GPIO_PIN3    3
#define GPIO_PIN4    4
#define GPIO_PIN5    5
#define GPIO_PIN6    6
#define GPIO_PIN7    7

/* Direction */
#define GPIO_OUTPUT  0
#define GPIO_INPUT   1

/* Values */
#define GPIO_LOW     0
#define GPIO_HIGH    1

/* External Interrupt Configuration */
#define EXT_INT_PORT GPIO_PORTB
#define EXT_INT_PIN GPIO_PIN0
#define GIE_BIT 7
#define INTE_BIT 4
#define INTF_BIT 1
/* Edge types */
#define INTEDGE_BIT 6
#define rising_edge 1
#define falling_edge 0

void EXT_INT_Init(void);
void EXT_INT_Enable(void);
void EXT_INT_Disable(void);
void EXT_INT_SetEdge(u8 Edgetype);
void EXT_INT_SetCallback(void (*Callback)(void));    



#endif