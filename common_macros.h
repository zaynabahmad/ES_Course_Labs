// common_macros.h - Bit manipulation macros
#ifndef COMMON_MACROS_H
#define COMMON_MACROS_H

#define SET_BIT(REG, BIT) ((REG) |= (1 << (BIT)))
#define CLEAR_BIT(REG, BIT) ((REG) &= ~(1 << (BIT)))
#define TOGGLE_BIT(REG, BIT) ((REG) ^= (1 << (BIT)))
#define READ_BIT(REG, BIT) (((REG) >> (BIT)) & 1)

#endif