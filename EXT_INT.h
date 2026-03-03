#ifndef EXT_INT_H
#define EXT_INT_H

void EXT_INT0_Init(void);
void EXT_INT0_Enable(void);
void EXT_INT0_Disable(void);
void EXT_INT0_SetEdge(unsigned char edge_type); // 1 for Rising, 0 for Falling
void EXT_INT0_SetCallback(void (*ptr)(void));

#endif