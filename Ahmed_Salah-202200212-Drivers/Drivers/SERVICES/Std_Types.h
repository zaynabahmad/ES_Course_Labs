#ifndef STD_TYPES_H
#define STD_TYPES_H

/* Unsigned Data Types */
typedef unsigned char         u8;
typedef unsigned short int    u16;
typedef unsigned long int     u32;

/* Signed Data Types */
typedef signed char           s8;
typedef signed short int      s16;
typedef signed long int       s32;

/* Floating Point Types */
typedef float                 f32;
typedef double                f64;

/* Standard Logic Values */
#define HIGH                  1
#define LOW                   0

#define TRUE                  1
#define FALSE                 0

#define ENABLE                1
#define DISABLE               0

#define INPUT                 1
#define OUTPUT                0

/* To support Task 1 (Switch Logic) */
#define PRESSED               1
#define RELEASED              0

#define NULL                  ((void*)0)

#endif