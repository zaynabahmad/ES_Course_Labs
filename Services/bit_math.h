#ifndef BIT_MATH_H
#define BIT_MATH_H

/* Set a specific bit to 1 */
#define SET_BIT(REG, BIT)     (REG |= (1 << BIT))

/* Clear a specific bit to 0 */
#define CLR_BIT(REG, BIT)     (REG &= ~(1 << BIT))

/* Toggle a specific bit */
#define TOG_BIT(REG, BIT)     (REG ^= (1 << BIT))

/* Get the value of a specific bit (returns 0 or 1) */
#define GET_BIT(REG, BIT)     ((REG >> BIT) & 0x01)

/* Macro to write a whole port at once */
#define WRITE_REG(REG, VAL)   (REG = VAL)

/* Macro to read a whole port at once */
#define READ_REG(REG)         (REG)

#endif