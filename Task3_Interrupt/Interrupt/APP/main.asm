
_main:

;main.c,3 :: 		void main() {
;main.c,4 :: 		EXTI0_Service_Init();   // Initialize LED + INT0
	CALL       _EXTI0_Service_Init+0
;main.c,6 :: 		while(1){
L_main0:
;main.c,7 :: 		EXTI0_Service_Loop();  // Handle LED toggling safely
	CALL       _EXTI0_Service_Loop+0
;main.c,8 :: 		}
	GOTO       L_main0
;main.c,9 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
