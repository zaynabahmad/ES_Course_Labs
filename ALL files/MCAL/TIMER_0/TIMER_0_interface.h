#ifndef TIMER_0_INTERFACE_H
#define TIMER_0_INTERFACE_H

#include "../../SERVICES/STD_TYPES.h"

/*
 * Function: TIMER0_Init
 * --------------------
 * Initialize Timer0 based on configuration:
 * - Prescaler
 * - Mode (Timer/Counter)
 * - Preload value
 */
void TIMER0_Init(void);


/*
 * Function: TIMER0_Enable
 * -----------------------
 * Enable Timer0 interrupt and global interrupt
 */
void TIMER0_Enable(void);


/*
 * Function: TIMER0_Disable
 * ------------------------
 * Disable Timer0 interrupt
 */
void TIMER0_Disable(void);


/*
 * Function: TIMER0_Reload
 * -----------------------
 * Reload Timer0 with predefined preload value
 * (Used inside ISR for periodic interrupts)
 */
void TIMER0_Reload(void);


/*
 * Function: TIMER0_GetValue
 * -------------------------
 * Returns current value of TMR0 register
 */
u8 TIMER0_GetValue(void);


/*
 * Function: TIMER0_SetCallback
 * ----------------------------
 * Set user-defined function to be executed
 * on Timer0 overflow interrupt
 */
void TIMER0_SetCallback(void (*Callback)(void));


/*
 * Function: TIMER0_ISR
 * --------------------
 * Handles Timer0 interrupt:
 * - Clears overflow flag
 * - Reloads timer
 * - Calls callback function
 */
void TIMER0_ISR(void);

#endif