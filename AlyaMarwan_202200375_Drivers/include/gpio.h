#ifndef GPIO_H
#define GPIO_H
#include "std_types.h"
#include "gpio_cfg.h"


#include "std_types.h"
#include "gpio_cfg.h"

void  GPIO_SetPinDirection(uint8 port, uint8 pin, uint8 direction);
void  GPIO_WritePin(uint8 port, uint8 pin, uint8 value);
uint8 GPIO_ReadPin(uint8 port, uint8 pin);
void  GPIO_SetPortDirection(uint8 port, uint8 direction);
void  GPIO_WritePort(uint8 port, uint8 value);
uint8 GPIO_ReadPort(uint8 port);

#endif