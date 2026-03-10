#include "../HAL/LED/LED_interface.h"        /* [cite: 2] */
#include "../MCAL/ext_int_interface.h"

u16 interrupt_count = 0;
u8  seconds_elapsed = 0;





void Toggle_LED_Callback(void) {

    PORTA ^= (1 << 2);
}

int main() {
   
    LED_Init(_PORTA, 2);

    EXT_INTO_Init();
    EXT_INTO_SetEdge(1); // 1 for Rising Edge [cite: 645]

    /* Register the callback function [cite: 802, 809] */
    EXT_INTO_SetCallback(Toggle_LED_Callback);

   
    EXT_INTO_Enable();

    while(1) {
        
    }

    return 0;

}
