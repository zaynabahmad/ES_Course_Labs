
_SWITCH_Init:

;switch_program.c,5 :: 		void SWITCH_Init(u8 port, u8 pin)
;switch_program.c,7 :: 		GPIO_setPinDirection(port, pin, GPIO_INPUT);
	MOVF       FARG_SWITCH_Init_port+0, 0
	MOVWF      FARG_GPIO_setPinDirection_port+0
	MOVF       FARG_SWITCH_Init_pin+0, 0
	MOVWF      FARG_GPIO_setPinDirection_pin+0
	MOVLW      1
	MOVWF      FARG_GPIO_setPinDirection_direction+0
	CALL       _GPIO_setPinDirection+0
;switch_program.c,8 :: 		}
L_end_SWITCH_Init:
	RETURN
; end of _SWITCH_Init

_SWITCH_GetState:

;switch_program.c,10 :: 		u8 SWITCH_GetState(u8 port, u8 pin)
;switch_program.c,12 :: 		return GPIO_getPinValue(port, pin);
	MOVF       FARG_SWITCH_GetState_port+0, 0
	MOVWF      FARG_GPIO_getPinValue_port+0
	MOVF       FARG_SWITCH_GetState_pin+0, 0
	MOVWF      FARG_GPIO_getPinValue_pin+0
	CALL       _GPIO_getPinValue+0
;switch_program.c,13 :: 		}
L_end_SWITCH_GetState:
	RETURN
; end of _SWITCH_GetState
