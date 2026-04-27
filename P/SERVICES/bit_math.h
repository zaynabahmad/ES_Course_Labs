#ifndef BIT_MATH_H
#define BIT_MATH_H

/* Single-bit manipulation macros */
#define SET_BIT(REG, BIT)    ((REG) |=  (1u << (BIT)))
#define CLR_BIT(REG, BIT)    ((REG) &= ~(1u << (BIT)))
#define TOG_BIT(REG, BIT)    ((REG) ^=  (1u << (BIT)))
#define GET_BIT(REG, BIT)    (((REG) >> (BIT)) & 0x01u)

#endif
