#include "../SERVICES/exti_service.h"

void main() {
    EXTI0_Service_Init();   // Initialize LED + INT0

    while(1){
        EXTI0_Service_Loop();  // Handle LED toggling safely
    }
}