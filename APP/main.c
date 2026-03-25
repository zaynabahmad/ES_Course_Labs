
#include "../HAL/PUSH_BUTTON/PUSH_BUTTON_INTERFACE.h"
#include "../MCAL/GPIO/GPIO_interface.h"
#include "../HAL/MOTOR/MOTOR_INTERFACE.h"

#define MaxSpeed 250

 volatile unsigned int cnt = 4;
void main() {

    PUSH_BUTTON_Init(GPIO_PORTB , GPIO_PIN0);

     Motor_Init();
     ForwardMotor(MaxSpeed/cnt);
    if (BUTTON_Read(GPIO_PORTB , GPIO_PIN0)) {
        if (cnt == 1) {
         cnt = 4 ;

         }
         cnt --;
    }

}

