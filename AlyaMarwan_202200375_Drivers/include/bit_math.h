#ifndef BIT_MATH_H
#define BIT_MATH_H

/* Set a specific bit in a register */
#define SET_BIT(REG, BIT)       (REG |=  (1 << BIT))

/* Clear a specific bit in a register */
#define CLR_BIT(REG, BIT)       (REG &= ~(1 << BIT))

/* Toggle a specific bit in a register */
#define TOG_BIT(REG, BIT)       (REG ^=  (1 << BIT))

/* Read a specific bit from a register */
#define GET_BIT(REG, BIT)       ((REG >> BIT) & 1)

#endif