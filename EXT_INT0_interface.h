 #ifndef EXT_INT0_INTERFACE_H
 #define EXT_INT0_INTERFACE_H
 
 #include "../../SERVICES/STD_TYPES.h"
 
 /* Edge types for INT0 */
 #define EXT_INT0_RISING_EDGE   0u
 #define EXT_INT0_FALLING_EDGE  1u
 
 void EXT_INT0_Init(void);
 void EXT_INT0_Enable(void);
 void EXT_INT0_Disable(void);
 void EXT_INT0_SetEdge(u8 edge_type);
 void EXT_INT0_SetCallback(void (*ptr)(void));
 
 #endif
