// std_types.h - For MikroC PRO (bool is already defined by compiler)
#ifndef STD_TYPES_H
#define STD_TYPES_H

typedef unsigned char uint8;
typedef signed char sint8;
typedef unsigned int uint16;
typedef signed int sint16;
typedef unsigned long uint32;
typedef signed long sint32;

// DO NOT redefine bool, true, false - MikroC PRO already has them!
// Just use them directly in your code

#define NULL 0

#endif