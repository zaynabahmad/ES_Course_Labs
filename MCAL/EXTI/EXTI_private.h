#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H

#define INTCON  (*((volatile u8*)0x8B))
#define OPTION_REG  (*((volatile u8*)0x81))



#define RISING_EDGE  1
#define FALLING_EDGE 0

#endif