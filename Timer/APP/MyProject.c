#include "../HAL/LED/LED_interface.h"        /* [cite: 2] */
#include "../MCAL/ext_int_interface.h"

u16 interrupt_count = 0;
u8  seconds_elapsed = 0;





void Toggle_LED_Callback(void) {

    PORTA ^= (1 << 2);
}

int main() {
    /* Initialize LED on PORTA, Pin 2 as seen in your snippet [cite: 9] */
    LED_Init(_PORTA, 2);

    /* Initialize External Interrupt 0 (RB0) [cite: 637, 803] */
    EXT_INTO_Init();
    EXT_INTO_SetEdge(1); // 1 for Rising Edge [cite: 645]

    /* Register the callback function [cite: 802, 809] */
    EXT_INTO_SetCallback(Toggle_LED_Callback);

    /* Enable Interrupts [cite: 653, 676] */
    EXT_INTO_Enable();

    while(1) {
        /* Main loop free for background tasks [cite: 703] */
    }

    return 0;
}