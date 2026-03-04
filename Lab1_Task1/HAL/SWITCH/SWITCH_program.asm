
_SWITCH_Init:

;SWITCH_program.c,4 :: 		void SWITCH_Init(uint8 port, uint8 pin)
;SWITCH_program.c,7 :: 		GPIO_SetPinDirection(port, pin, GPIO_INPUT);
	MOVF       FARG_SWITCH_Init_port+0, 0
	MOVWF      FARG_GPIO_SetPinDirection_port+0
	MOVF       FARG_SWITCH_Init_pin+0, 0
	MOVWF      FARG_GPIO_SetPinDirection_pin+0
	MOVLW      1
	MOVWF      FARG_GPIO_SetPinDirection_direction+0
	CALL       _GPIO_SetPinDirection+0
;SWITCH_program.c,8 :: 		}
L_end_SWITCH_Init:
	RETURN
; end of _SWITCH_Init

_SWITCH_Read:

;SWITCH_program.c,10 :: 		uint8 SWITCH_Read(uint8 port, uint8 pin)
;SWITCH_program.c,12 :: 		return GPIO_ReadPin(port, pin);
	MOVF       FARG_SWITCH_Read_port+0, 0
	MOVWF      FARG_GPIO_ReadPin_port+0
	MOVF       FARG_SWITCH_Read_pin+0, 0
	MOVWF      FARG_GPIO_ReadPin_pin+0
	CALL       _GPIO_ReadPin+0
;SWITCH_program.c,13 :: 		}
L_end_SWITCH_Read:
	RETURN
; end of _SWITCH_Read
