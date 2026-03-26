#ifndef BIT_MATH_H
#define BIT_MATH_H

/* Set bit 'Bit' in register 'Reg' */
#define SET_BIT(Reg, Bit)      (Reg |=  (1 << Bit))

/* Clear bit 'Bit' in register 'Reg' */
#define CLR_BIT(Reg, Bit)      (Reg &= ~(1 << Bit))

/* Toggle bit 'Bit' in register 'Reg' */
#define TOG_BIT(Reg, Bit)      (Reg ^=  (1 << Bit))

/* Get value of bit 'Bit' in register 'Reg' */
#define GET_BIT(Reg, Bit)      ((Reg >> Bit) & 1)

/* Circular shift right (Useful for LED Sequence Tasks) */
#define RSHFT_REG(Reg, n)      (Reg = (Reg >> n) | (Reg << (8-n)))

/* Circular shift left (Useful for LED Sequence Tasks) */
#define LSHFT_REG(Reg, n)      (Reg = (Reg << n) | (Reg >> (8-n)))

/* Assign a value to a whole register */
#define ASSIGN_REG(Reg, Value) (Reg = Value)

#endif