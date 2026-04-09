
_Button_Pressed_Callback:

;ext_int_test.c,5 :: 		void Button_Pressed_Callback(void) {
;ext_int_test.c,6 :: 		LED_Toggle(GPIO_PORTC, GPIO_PIN0);
	MOVLW      2
	MOVWF      FARG_LED_Toggle_Port+0
	CLRF       FARG_LED_Toggle_Pin+0
	CALL       _LED_Toggle+0
;ext_int_test.c,7 :: 		}
L_end_Button_Pressed_Callback:
	RETURN
; end of _Button_Pressed_Callback

_ext_int_test_run:

;ext_int_test.c,9 :: 		void ext_int_test_run(void) {
;ext_int_test.c,11 :: 		LED_Init(GPIO_PORTC, GPIO_PIN0);
	MOVLW      2
	MOVWF      FARG_LED_Init_Port+0
	CLRF       FARG_LED_Init_Pin+0
	CALL       _LED_Init+0
;ext_int_test.c,14 :: 		EXT_INT_Init();
	CALL       _EXT_INT_Init+0
;ext_int_test.c,17 :: 		EXT_INT_SetCallback(Button_Pressed_Callback);
	MOVLW      _Button_Pressed_Callback+0
	MOVWF      FARG_EXT_INT_SetCallback_Callback+0
	MOVLW      hi_addr(_Button_Pressed_Callback+0)
	MOVWF      FARG_EXT_INT_SetCallback_Callback+1
	MOVLW      0
	MOVWF      FARG_EXT_INT_SetCallback_Callback+2
	MOVLW      0
	CALL       _EXT_INT_SetCallback+0
;ext_int_test.c,20 :: 		EXT_INT_SetEdge(falling_edge);
	CLRF       FARG_EXT_INT_SetEdge_Edgetype+0
	CALL       _EXT_INT_SetEdge+0
;ext_int_test.c,23 :: 		EXT_INT_Enable();
	CALL       _EXT_INT_Enable+0
;ext_int_test.c,25 :: 		while(1) {
L_ext_int_test_run0:
;ext_int_test.c,27 :: 		}
	GOTO       L_ext_int_test_run0
;ext_int_test.c,28 :: 		}
L_end_ext_int_test_run:
	RETURN
; end of _ext_int_test_run
