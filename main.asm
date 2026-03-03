
_My_App_Task:

;main.c,5 :: 		void My_App_Task(void) {
;main.c,6 :: 		LED_Toggle();
	CALL       _LED_Toggle+0
;main.c,7 :: 		}
L_end_My_App_Task:
	RETURN
; end of _My_App_Task

_main:

;main.c,9 :: 		void main() {
;main.c,11 :: 		LED_Init();
	CALL       _LED_Init+0
;main.c,14 :: 		EXT_INT0_Init();
	CALL       _EXT_INT0_Init+0
;main.c,17 :: 		EXT_INT0_SetCallback(My_App_Task);
	MOVLW      _My_App_Task+0
	MOVWF      FARG_EXT_INT0_SetCallback_ptr+0
	MOVLW      hi_addr(_My_App_Task+0)
	MOVWF      FARG_EXT_INT0_SetCallback_ptr+1
	MOVLW      0
	MOVWF      FARG_EXT_INT0_SetCallback_ptr+2
	MOVLW      0
	CALL       _EXT_INT0_SetCallback+0
;main.c,19 :: 		while(1) {
L_main0:
;main.c,22 :: 		}
	GOTO       L_main0
;main.c,23 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
