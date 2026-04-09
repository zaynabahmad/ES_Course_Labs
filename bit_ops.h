#ifndef BIT_OPS_H
#define BIT_OPS_H

#define BIT_SET(reg,bit)   ((reg) |=  (1U << (bit)))
#define BIT_CLEAR(reg,bit) ((reg) &= ~(1U << (bit)))
#define BIT_FLIP(reg,bit)  ((reg) ^=  (1U << (bit)))
#define BIT_READ(reg,bit)  (((reg) >> (bit)) & 1U)

#endif