#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

#include "D:\Uni\Y4 S2\Embedded Systems\Final\SERVICES\STD_TYPES.h"

/* Return codes */
#define GPIO_OK              0u
#define GPIO_ERR_INVALID    0xFFu

/* ---- Public function prototypes ---- */

unsigned char GPIO_voidSetPinDirection(unsigned char port,
                                       unsigned char pin,
                                       unsigned char dir);

unsigned char GPIO_voidSetPinValue(unsigned char port,
                                   unsigned char pin,
                                   unsigned char val);


unsigned char GPIO_u8GetPinValue(unsigned char port,
                                 unsigned char pin);

unsigned char GPIO_voidTogglePin(unsigned char port,
                                 unsigned char pin);

unsigned char GPIO_voidSetPortDirection(unsigned char port,
                                        unsigned char dir_mask);

unsigned char GPIO_voidSetPortValue(unsigned char port,
                                    unsigned char value);

#endif /* GPIO_INTERFACE_H */