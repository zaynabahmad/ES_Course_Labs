
_SWITCH_Init:

;SWITCH.c,4 :: 		void SWITCH_Init(char port, char pin)
;SWITCH.c,6 :: 		GPIO_SetPinDirection(port, pin, INPUT);
	MOVF       FARG_SWITCH_Init_port+0, 0
	MOVWF      FARG_GPIO_SetPinDirection_port+0
	MOVF       FARG_SWITCH_Init_pin+0, 0
	MOVWF      FARG_GPIO_SetPinDirection_pin+0
	MOVLW      1
	MOVWF      FARG_GPIO_SetPinDirection_direction+0
	CALL       _GPIO_SetPinDirection+0
;SWITCH.c,7 :: 		}
L_end_SWITCH_Init:
	RETURN
; end of _SWITCH_Init

_SWITCH_Read:

;SWITCH.c,9 :: 		char SWITCH_Read(char port, char pin)
;SWITCH.c,11 :: 		return GPIO_ReadPin(port, pin);
	MOVF       FARG_SWITCH_Read_port+0, 0
	MOVWF      FARG_GPIO_ReadPin_port+0
	MOVF       FARG_SWITCH_Read_pin+0, 0
	MOVWF      FARG_GPIO_ReadPin_pin+0
	CALL       _GPIO_ReadPin+0
;SWITCH.c,12 :: 		}
L_end_SWITCH_Read:
	RETURN
; end of _SWITCH_Read
