
_LED_Init:

;LED_program.c,4 :: 		void LED_Init(uint8 port, uint8 pin)
;LED_program.c,6 :: 		GPIO_SetPinDirection(port, pin, GPIO_OUTPUT);
	MOVF       FARG_LED_Init_port+0, 0
	MOVWF      FARG_GPIO_SetPinDirection_port+0
	MOVF       FARG_LED_Init_pin+0, 0
	MOVWF      FARG_GPIO_SetPinDirection_pin+0
	CLRF       FARG_GPIO_SetPinDirection_direction+0
	CALL       _GPIO_SetPinDirection+0
;LED_program.c,7 :: 		GPIO_WritePin(port, pin, GPIO_LOW);   /* OFF initially */
	MOVF       FARG_LED_Init_port+0, 0
	MOVWF      FARG_GPIO_WritePin_port+0
	MOVF       FARG_LED_Init_pin+0, 0
	MOVWF      FARG_GPIO_WritePin_pin+0
	CLRF       FARG_GPIO_WritePin_value+0
	CALL       _GPIO_WritePin+0
;LED_program.c,8 :: 		}
L_end_LED_Init:
	RETURN
; end of _LED_Init

_LED_On:

;LED_program.c,10 :: 		void LED_On(uint8 port, uint8 pin)
;LED_program.c,12 :: 		GPIO_WritePin(port, pin, GPIO_HIGH);
	MOVF       FARG_LED_On_port+0, 0
	MOVWF      FARG_GPIO_WritePin_port+0
	MOVF       FARG_LED_On_pin+0, 0
	MOVWF      FARG_GPIO_WritePin_pin+0
	MOVLW      1
	MOVWF      FARG_GPIO_WritePin_value+0
	CALL       _GPIO_WritePin+0
;LED_program.c,13 :: 		}
L_end_LED_On:
	RETURN
; end of _LED_On

_LED_Off:

;LED_program.c,15 :: 		void LED_Off(uint8 port, uint8 pin)
;LED_program.c,17 :: 		GPIO_WritePin(port, pin, GPIO_LOW);
	MOVF       FARG_LED_Off_port+0, 0
	MOVWF      FARG_GPIO_WritePin_port+0
	MOVF       FARG_LED_Off_pin+0, 0
	MOVWF      FARG_GPIO_WritePin_pin+0
	CLRF       FARG_GPIO_WritePin_value+0
	CALL       _GPIO_WritePin+0
;LED_program.c,18 :: 		}
L_end_LED_Off:
	RETURN
; end of _LED_Off

_LED_Toggle:

;LED_program.c,20 :: 		void LED_Toggle(uint8 port, uint8 pin)
;LED_program.c,22 :: 		uint8 current = GPIO_ReadPin(port, pin);
	MOVF       FARG_LED_Toggle_port+0, 0
	MOVWF      FARG_GPIO_ReadPin_port+0
	MOVF       FARG_LED_Toggle_pin+0, 0
	MOVWF      FARG_GPIO_ReadPin_pin+0
	CALL       _GPIO_ReadPin+0
;LED_program.c,23 :: 		GPIO_WritePin(port, pin, !current);
	MOVF       FARG_LED_Toggle_port+0, 0
	MOVWF      FARG_GPIO_WritePin_port+0
	MOVF       FARG_LED_Toggle_pin+0, 0
	MOVWF      FARG_GPIO_WritePin_pin+0
	MOVF       R0+0, 0
	MOVLW      1
	BTFSS      STATUS+0, 2
	MOVLW      0
	MOVWF      FARG_GPIO_WritePin_value+0
	CALL       _GPIO_WritePin+0
;LED_program.c,24 :: 		}
L_end_LED_Toggle:
	RETURN
; end of _LED_Toggle
