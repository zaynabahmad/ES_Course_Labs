#ifndef SW_INTERFACE_H
#define SW_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"


typedef enum {
    SW_ACTIVE_LOW = 0,
    SW_ACTIVE_HIGH
} SW_Logic_t;


typedef enum {
    SW_RELEASED = 0,
    SW_PRESSED
} SW_Status_t;


typedef struct {
    u8 Port;
    u8 Pin;
    SW_Logic_t Logic;
} SW_Type;




void SW_voidInit(const SW_Type* Copy_pswSwitch);

SW_Status_t SW_stGetState(const SW_Type* Copy_pswSwitch);

#endif /* SW_INTERFACE_H */