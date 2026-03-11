#ifndef TIMER0_INTERFACE_H
#define TIMER0_INTERFACE_H

void TIMER0_voidInit(void);
void TIMER0_voidSetPreload(unsigned char Copy_u8Preload);
void TIMER0_voidEnableInterrupt(void);
void TIMER0_voidSetCallBack(void (*Copy_ptrToFunc)(void));

#endif