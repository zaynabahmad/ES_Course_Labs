
_APP_ToggleLED:

;main.c,5 :: 		void APP_ToggleLED(void)
;main.c,7 :: 		LED_Toggle();
	CALL       _LED_Toggle+0
;main.c,8 :: 		}
L_end_APP_ToggleLED:
	RETURN
; end of _APP_ToggleLED

_main:

;main.c,10 :: 		void main()
;main.c,12 :: 		LED_Init();
	CALL       _LED_Init+0
;main.c,13 :: 		SWITCH_Init(0);
	CLRF       FARG_SWITCH_Init_pin+0
	CALL       _SWITCH_Init+0
;main.c,15 :: 		EXT_INT0_Init();
	CALL       _EXT_INT0_Init+0
;main.c,16 :: 		EXT_INT0_SetEdge(RISING_EDGE);
	MOVLW      1
	MOVWF      FARG_EXT_INT0_SetEdge_edge_type+0
	CALL       _EXT_INT0_SetEdge+0
;main.c,17 :: 		EXT_INT0_SetCallback(APP_ToggleLED);
	MOVLW      _APP_ToggleLED+0
	MOVWF      FARG_EXT_INT0_SetCallback_ptr+0
	MOVLW      hi_addr(_APP_ToggleLED+0)
	MOVWF      FARG_EXT_INT0_SetCallback_ptr+1
	MOVLW      0
	MOVWF      FARG_EXT_INT0_SetCallback_ptr+2
	MOVLW      0
	CALL       _EXT_INT0_SetCallback+0
;main.c,18 :: 		EXT_INT0_Enable();
	CALL       _EXT_INT0_Enable+0
;main.c,20 :: 		while(1)
L_main0:
;main.c,23 :: 		}
	GOTO       L_main0
;main.c,24 :: 		}
L_end_main:
	GOTO       $+0
; end of _main
