
_LED_Init:

;LED.c,4 :: 		void LED_Init(char port, char pin)
;LED.c,6 :: 		GPIO_SetPinDirection(port, pin, OUTPUT);
	MOVF       FARG_LED_Init_port+0, 0
	MOVWF      FARG_GPIO_SetPinDirection_port+0
	MOVF       FARG_LED_Init_pin+0, 0
	MOVWF      FARG_GPIO_SetPinDirection_pin+0
	CLRF       FARG_GPIO_SetPinDirection_direction+0
	CALL       _GPIO_SetPinDirection+0
;LED.c,7 :: 		}
L_end_LED_Init:
	RETURN
; end of _LED_Init

_LED_On:

;LED.c,9 :: 		void LED_On(char port, char pin)
;LED.c,11 :: 		GPIO_WritePin(port, pin, HIGH);
	MOVF       FARG_LED_On_port+0, 0
	MOVWF      FARG_GPIO_WritePin_port+0
	MOVF       FARG_LED_On_pin+0, 0
	MOVWF      FARG_GPIO_WritePin_pin+0
	MOVLW      1
	MOVWF      FARG_GPIO_WritePin_value+0
	CALL       _GPIO_WritePin+0
;LED.c,12 :: 		}
L_end_LED_On:
	RETURN
; end of _LED_On

_LED_Off:

;LED.c,14 :: 		void LED_Off(char port, char pin)
;LED.c,16 :: 		GPIO_WritePin(port, pin, LOW);
	MOVF       FARG_LED_Off_port+0, 0
	MOVWF      FARG_GPIO_WritePin_port+0
	MOVF       FARG_LED_Off_pin+0, 0
	MOVWF      FARG_GPIO_WritePin_pin+0
	CLRF       FARG_GPIO_WritePin_value+0
	CALL       _GPIO_WritePin+0
;LED.c,17 :: 		}
L_end_LED_Off:
	RETURN
; end of _LED_Off
