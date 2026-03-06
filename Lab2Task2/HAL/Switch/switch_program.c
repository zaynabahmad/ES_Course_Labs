#include "switch_interface.h"

void SWITCH_Init(unsigned char port, unsigned char pin)
{
    setpindirection(port, pin, INPUT);
}