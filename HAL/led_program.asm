
_LED_Init:

;led_program.c,4 :: 		void LED_Init(u8 port, u8 pin)
;led_program.c,6 :: 		GPIO_setPinDirection(port, pin, GPIO_OUTPUT);
	MOVF       FARG_LED_Init_port+0, 0
	MOVWF      FARG_GPIO_setPinDirection_port+0
	MOVF       FARG_LED_Init_pin+0, 0
	MOVWF      FARG_GPIO_setPinDirection_pin+0
	CLRF       FARG_GPIO_setPinDirection_direction+0
	CALL       _GPIO_setPinDirection+0
;led_program.c,7 :: 		}
L_end_LED_Init:
	RETURN
; end of _LED_Init

_LED_On:

;led_program.c,9 :: 		void LED_On(u8 port, u8 pin)
;led_program.c,11 :: 		GPIO_setPinValue(port, pin, GPIO_HIGH);
	MOVF       FARG_LED_On_port+0, 0
	MOVWF      FARG_GPIO_setPinValue_port+0
	MOVF       FARG_LED_On_pin+0, 0
	MOVWF      FARG_GPIO_setPinValue_pin+0
	MOVLW      1
	MOVWF      FARG_GPIO_setPinValue_value+0
	CALL       _GPIO_setPinValue+0
;led_program.c,12 :: 		}
L_end_LED_On:
	RETURN
; end of _LED_On

_LED_Off:

;led_program.c,14 :: 		void LED_Off(u8 port, u8 pin)
;led_program.c,16 :: 		GPIO_setPinValue(port, pin, GPIO_LOW);
	MOVF       FARG_LED_Off_port+0, 0
	MOVWF      FARG_GPIO_setPinValue_port+0
	MOVF       FARG_LED_Off_pin+0, 0
	MOVWF      FARG_GPIO_setPinValue_pin+0
	CLRF       FARG_GPIO_setPinValue_value+0
	CALL       _GPIO_setPinValue+0
;led_program.c,17 :: 		}
L_end_LED_Off:
	RETURN
; end of _LED_Off

_LED_Toggle:

;led_program.c,19 :: 		void LED_Toggle(u8 port, u8 pin)
;led_program.c,22 :: 		state ^= 1;
	MOVLW      1
	XORWF      LED_Toggle_state_L0+0, 0
	MOVWF      R0+0
	MOVF       R0+0, 0
	MOVWF      LED_Toggle_state_L0+0
;led_program.c,23 :: 		GPIO_setPinValue(port, pin, state);
	MOVF       FARG_LED_Toggle_port+0, 0
	MOVWF      FARG_GPIO_setPinValue_port+0
	MOVF       FARG_LED_Toggle_pin+0, 0
	MOVWF      FARG_GPIO_setPinValue_pin+0
	MOVF       R0+0, 0
	MOVWF      FARG_GPIO_setPinValue_value+0
	CALL       _GPIO_setPinValue+0
;led_program.c,24 :: 		}
L_end_LED_Toggle:
	RETURN
; end of _LED_Toggle
