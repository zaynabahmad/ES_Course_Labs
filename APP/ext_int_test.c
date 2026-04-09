#include "app_tests.h"

#include "../MCAL/EXT_INT/EXT_INT_Interface.h"

static void APP_ExtIntCallback(void)
{
}

void APP_Test_EXT_INT(void)
{
    EXT_INT_Init();
    EXT_INT_SetEdge(EXT_INT_FALLING_EDGE);
    EXT_INT_SetCallback(APP_ExtIntCallback);
    EXT_INT_Enable();
}
