#include "../MCAL/EXT_INT/EXT_INT_Interface.h"

void ExternalInterrupt_Test(void)
{
    /* Test 1: Initialize External Interrupt 0 (RB0) */
    EXT_INT0_Init();

    /* Test 2: Enable External Interrupt 0 */
    EXT_INT0_Enable();

    /* Test 3: Set callback for External Interrupt 0 */
    EXT_INT0_SetCallback(NULL_PTR);

    /* Test 4: Initialize External Interrupt 1 (RB1) */
    EXT_INT1_Init();

    /* Test 5: Enable External Interrupt 1 */
    EXT_INT1_Enable();

    /* Test 6: Set callback for External Interrupt 1 */
    EXT_INT1_SetCallback(NULL_PTR);

    /* Test 7: Initialize External Interrupt 2 (RB2) */
    EXT_INT2_Init();

    /* Test 8: Enable External Interrupt 2 */
    EXT_INT2_Enable();

    /* Test 9: Set callback for External Interrupt 2 */
    EXT_INT2_SetCallback(NULL_PTR);

    /* Test 10: Disable External Interrupt 0 */
    EXT_INT0_Disable();
}
