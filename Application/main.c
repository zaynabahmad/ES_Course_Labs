#include "C:\Users\engfa\OneDrive\Desktop\Embedded CIE 349\EmbeddedLab2\LabTask - External Interrupt (INT0) driver\INT0_Folders\MCAL\EXIT_INT0 .h"
#include "C:\Users\engfa\OneDrive\Desktop\Embedded CIE 349\EmbeddedLab2\LabTask - External Interrupt (INT0) driver\INT0_Folders\HAL\LED.h"
#include "C:\Users\engfa\OneDrive\Desktop\Embedded CIE 349\EmbeddedLab2\LabTask - External Interrupt (INT0) driver\INT0_Folders\HAL\SWITCH.h"

void APP_ToggleLED(void)
{
    LED_Toggle();
}

void main()
{
    LED_Init();
    SWITCH_Init(0);

    EXT_INT0_Init();
    EXT_INT0_SetEdge(RISING_EDGE);
    EXT_INT0_SetCallback(APP_ToggleLED);
    EXT_INT0_Enable();

    while(1)
    {
        // Main loop empty
    }
}