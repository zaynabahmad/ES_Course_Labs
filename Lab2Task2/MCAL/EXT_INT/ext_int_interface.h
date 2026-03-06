#ifndef EXT_INT_INTERFACE_H
#define EXT_INT_INTERFACE_H

void EXT_INT0_Init(void);

void EXT_INT0_Enable(void);

void EXT_INT0_Disable(void);

void EXT_INT0_SetEdge(unsigned char edge_type);

void EXT_INT0_SetCallback(void (*ptr)(void));

#endif