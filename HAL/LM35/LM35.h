#ifndef LM35_H
#define LM35_H
#include "../../MCAL/ADC/ADC_interface.h"
void LM35_init(u8 port, u8 pin);
u16 LM35_u16GetTemp(void);
#endif // LM35_H