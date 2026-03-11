#line 1 "D:/University/Spring_26/Embedded/Labs/MCAL/GPIO/MyProject.c"



u16 interrupt_count = 0;
u8 seconds_elapsed = 0;





void Toggle_LED_Callback(void) {

 PORTA ^= (1 << 2);
}

int main() {

 LED_Init(_PORTA, 2);


 EXT_INTO_Init();
 EXT_INTO_SetEdge(1);


 EXT_INTO_SetCallback(Toggle_LED_Callback);


 EXT_INTO_Enable();

 while(1) {

 }

 return 0;
}
