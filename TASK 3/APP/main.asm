
_App_vToggleLogic:

;main.c,5 :: 		void App_vToggleLogic(void) {
;main.c,6 :: 		HLED_vToggle();
	CALL       _HLED_vToggle+0
;main.c,7 :: 		}
L_end_App_vToggleLogic:
	RETURN
; end of _App_vToggleLogic

_main:

;main.c,9 :: 		void main(void) {
;main.c,10 :: 		HLED_vInit();
	CALL       _HLED_vInit+0
;main.c,11 :: 		MEXTI0_vSetCallback(App_vToggleLogic);
	MOVLW      _App_vToggleLogic+0
	MOVWF      FARG_MEXTI0_vSetCallback_ptr+0
	MOVLW      hi_addr(_App_vToggleLogic+0)
	MOVWF      FARG_MEXTI0_vSetCallback_ptr+1
	MOVLW      0
	MOVWF      FARG_MEXTI0_vSetCallback_ptr+2
	MOVLW      0
	CALL       _MEXTI0_vSetCallback+0
;main.c,12 :: 		MEXTI0_vInit();
	CALL       _MEXTI0_vInit+0
;main.c,14 :: 		while(1) {
L_main0:
;main.c,16 :: 		}
	GOTO       L_main0
;main.c,17 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
