
_Toggle_LED_Callback:

;MyProject.c,11 :: 		void Toggle_LED_Callback(void) {
;MyProject.c,13 :: 		PORTA ^= (1 << 2);
	MOVLW      4
	XORWF      PORTA+0, 1
;MyProject.c,14 :: 		}
L_end_Toggle_LED_Callback:
	RETURN
; end of _Toggle_LED_Callback

_main:

;MyProject.c,16 :: 		int main() {
;MyProject.c,18 :: 		LED_Init(_PORTA, 2);
	CLRF       FARG_LED_Init_port+0
	MOVLW      2
	MOVWF      FARG_LED_Init_pin+0
	CALL       _LED_Init+0
;MyProject.c,21 :: 		EXT_INTO_Init();
	CALL       _EXT_INTO_Init+0
;MyProject.c,22 :: 		EXT_INTO_SetEdge(1); // 1 for Rising Edge [cite: 645]
	MOVLW      1
	MOVWF      FARG_EXT_INTO_SetEdge_edge_type+0
	CALL       _EXT_INTO_SetEdge+0
;MyProject.c,25 :: 		EXT_INTO_SetCallback(Toggle_LED_Callback);
	MOVLW      _Toggle_LED_Callback+0
	MOVWF      FARG_EXT_INTO_SetCallback_ptr+0
	MOVLW      hi_addr(_Toggle_LED_Callback+0)
	MOVWF      FARG_EXT_INTO_SetCallback_ptr+1
	MOVLW      0
	MOVWF      FARG_EXT_INTO_SetCallback_ptr+2
	MOVLW      0
	CALL       _EXT_INTO_SetCallback+0
;MyProject.c,28 :: 		EXT_INTO_Enable();
	CALL       _EXT_INTO_Enable+0
;MyProject.c,30 :: 		while(1) {
L_main0:
;MyProject.c,32 :: 		}
	GOTO       L_main0
;MyProject.c,35 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
