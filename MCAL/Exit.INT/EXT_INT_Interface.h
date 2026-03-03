#ifndef EXT_INT_INTERFACE_H
#define EXT_INT_INTERFACE_H

#define RISING_EDGE   1
#define FALLING_EDGE  0

#define INT_LED_PORT     PORTD
#define INT_LED_PIN      3

void EXT_INT0_Init(void);
void EXT_INT0_Enable(void);
void EXT_INT0_Disable(void);
void EXT_INT0_SetEdge(unsigned char edge_type);
void EXT_INT0_SetCallback(void (*ptr)(void));

#endif