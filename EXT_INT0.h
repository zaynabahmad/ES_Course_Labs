#ifndef EXT_INT0_H
#define EXT_INT0_H


typedef enum {
    FALLING_EDGE_TRIGGER = 0,
    RISING_EDGE_TRIGGER  = 1
} ExtInt0_EdgeType_t;

typedef void (*ExtInt0_CallbackFunc_t)(void);


void EXT_INT0_Initialize(void);
void EXT_INT0_SetTriggerEdge(ExtInt0_EdgeType_t edge);
void EXT_INT0_EnableInterrupt(void);
void EXT_INT0_DisableInterrupt(void);
void EXT_INT0_RegisterCallback(ExtInt0_CallbackFunc_t callbackFunc);

#endif