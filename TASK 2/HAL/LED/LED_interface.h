#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

void LED_Init(char port, char pin);
void LED_On(char port, char pin);
void LED_Off(char port, char pin);

#endif