
_GPIO_Test:

;gpio_test.c,4 :: 		void GPIO_Test(void)
;gpio_test.c,6 :: 		GPIO_SetPinDirection(PORTB, PIN0, OUTPUT);
	MOVLW      1
	MOVWF      FARG_GPIO_SetPinDirection_port+0
	CLRF       FARG_GPIO_SetPinDirection_pin+0
	CLRF       FARG_GPIO_SetPinDirection_direction+0
	CALL       _GPIO_SetPinDirection+0
;gpio_test.c,8 :: 		while(1)
L_GPIO_Test0:
;gpio_test.c,10 :: 		GPIO_WritePin(PORTB, PIN0, HIGH);
	MOVLW      1
	MOVWF      FARG_GPIO_WritePin_port+0
	CLRF       FARG_GPIO_WritePin_pin+0
	MOVLW      1
	MOVWF      FARG_GPIO_WritePin_value+0
	CALL       _GPIO_WritePin+0
;gpio_test.c,11 :: 		Delay_ms(500);
	MOVLW      6
	MOVWF      R11+0
	MOVLW      19
	MOVWF      R12+0
	MOVLW      173
	MOVWF      R13+0
L_GPIO_Test2:
	DECFSZ     R13+0, 1
	GOTO       L_GPIO_Test2
	DECFSZ     R12+0, 1
	GOTO       L_GPIO_Test2
	DECFSZ     R11+0, 1
	GOTO       L_GPIO_Test2
	NOP
	NOP
;gpio_test.c,13 :: 		GPIO_WritePin(PORTB, PIN0, LOW);
	MOVLW      1
	MOVWF      FARG_GPIO_WritePin_port+0
	CLRF       FARG_GPIO_WritePin_pin+0
	CLRF       FARG_GPIO_WritePin_value+0
	CALL       _GPIO_WritePin+0
;gpio_test.c,14 :: 		Delay_ms(500);
	MOVLW      6
	MOVWF      R11+0
	MOVLW      19
	MOVWF      R12+0
	MOVLW      173
	MOVWF      R13+0
L_GPIO_Test3:
	DECFSZ     R13+0, 1
	GOTO       L_GPIO_Test3
	DECFSZ     R12+0, 1
	GOTO       L_GPIO_Test3
	DECFSZ     R11+0, 1
	GOTO       L_GPIO_Test3
	NOP
	NOP
;gpio_test.c,15 :: 		}
	GOTO       L_GPIO_Test0
;gpio_test.c,16 :: 		}
L_end_GPIO_Test:
	RETURN
; end of _GPIO_Test
