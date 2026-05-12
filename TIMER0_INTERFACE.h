#ifndef TIMER0_INTERFACE_H
#define TIMER0_INTERFACE_H

#include "../SERVICES/STD_TYPES.h"

/* Clock source options */
#define TIMER0_CLK_INTERNAL  0
#define TIMER0_CLK_EXTERNAL  1

/* Prescaler on/off */
#define TIMER0_PRESCALER_ON   0
#define TIMER0_PRESCALER_OFF  1

/* Prescaler values (PS2:PS0 in OPTION_REG) */
#define TIMER0_PRESCALE_2    0x00  /* 1:2   */
#define TIMER0_PRESCALE_4    0x01  /* 1:4   */
#define TIMER0_PRESCALE_8    0x02  /* 1:8   */
#define TIMER0_PRESCALE_16   0x03  /* 1:16  */
#define TIMER0_PRESCALE_32   0x04  /* 1:32  */
#define TIMER0_PRESCALE_64   0x05  /* 1:64  */
#define TIMER0_PRESCALE_128  0x06  /* 1:128 */
#define TIMER0_PRESCALE_256  0x07  /* 1:256 */

void TIMER0_Init(void);
void TIMER0_SetPreload(u8 preload);
u8   TIMER0_GetValue(void);
void TIMER0_EnableInterrupt(void);
void TIMER0_DisableInterrupt(void);
void TIMER0_ClearFlag(void);
u8   TIMER0_GetFlag(void);
void TIMER0_SetCallback(void (*ptr)(void));
void TIMER0_HandleISR(void);

#endif
