#ifndef EI_H
#define EI_H

#define RISING_EDGE   1
#define FALLING_EDGE  0

void EI_Init(void);
void EI_SetEdge(unsigned char edge_type);
void EI_SetCallback(void (*ptr)(void));
void EI_Enable(void);
void EI_Disable(void);
#endif