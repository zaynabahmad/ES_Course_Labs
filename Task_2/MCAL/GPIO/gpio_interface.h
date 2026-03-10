#ifndef _GPIO_INTERFACE_H
#define _GPIO_INTERFACE_H

#include "../../SERVICES/std_types.h"



#define INPUT  1
#define OUTPUT 0                      /* [cite: 459] */
#define HIGH   1                      /* [cite: 184] */
#define LOW    0                      /* [cite: 184] */

/* Port Definitions */
#define _PORTA 0
#define _PORTB 1
#define _PORTC 2
#define _PORTD 3
#define _PORTE 4




void set_pin_direction(u8 port, u8 pin, u8 direction); /* [cite: 12] */
void set_pin_value(u8 port, u8 pin, u8 value);         /* [cite: 14] */
u8 get_pin_value(u8 port, u8 pin);            /* [cite: 16] */


#endif
