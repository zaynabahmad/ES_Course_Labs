/*
 * std_types.h
 * Standard types for PIC16F877A (MPLAB XC8)
 */

#ifndef STD_TYPES_H
#define STD_TYPES_H

typedef unsigned char       uint8;
typedef signed char         sint8;
typedef unsigned short      uint16;
typedef signed short        sint16;
typedef unsigned long       uint32;
typedef signed long         sint32;

typedef uint8               bool;
#define TRUE                1
#define FALSE               0

#ifndef NULL
#define NULL                ((void*)0)
#endif

#endif /* STD_TYPES_H */
