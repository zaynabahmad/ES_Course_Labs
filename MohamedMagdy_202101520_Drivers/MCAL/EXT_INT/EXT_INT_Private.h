#ifndef EXT_INT_PRIVATE_H
#define EXT_INT_PRIVATE_H

#ifndef INTCON
#define INTCON      (*((volatile u8*)0x0B))
#endif

#ifndef OPTION_REG
#define OPTION_REG  (*((volatile u8*)0x81))
#endif

#endif
