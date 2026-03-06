#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

#include "../SERVICES/STD_TYPES.h"
#include "../SERVICES/UTIL.h"

/* LED States */
#define LED_OFF    0
#define LED_ON     1

void LED_Init(u8 Port, u8 Pin);
void LED_On(u8 Port, u8 Pin);
void LED_Off(u8 Port, u8 Pin);
void LED_Toggle(u8 Port, u8 Pin);
void CHECKdelay(void);

//LED task week 1
void BLINKFAST(void);
void BLINKSLOW(void);



#endif