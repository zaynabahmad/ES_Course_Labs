/*
* MAIN APPLICATION LAYER
*
* LAB 1: Polling-based LED Sequences
* - Uncomment lab1_init() and lab1_run()
* - Comment out lab2_init()
*
* LAB 2: Interrupt-driven External Interrupt (ACTIVE)
* - Uncomment lab2_init()
* - Comment out lab1_init() and lab1_run()
*/

#include "lab1.c"
#include "lab2.c"

void main()
{
    /* LAB 1 - Polling Mode */
    /*
    lab1_init();
    while(1)
    {
        lab1_run();
    }
    */

    /* LAB 2 - Interrupt Mode (ACTIVE) */
    lab2_init();
    while(1){
        
    };
}