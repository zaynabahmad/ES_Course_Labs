
_usart_test_run:

;usart_test.c,3 :: 		void usart_test_run(void) {
;usart_test.c,5 :: 		UART_TX_Init();
	CALL       _UART_TX_Init+0
;usart_test.c,6 :: 		UART_RX_Init();
	CALL       _UART_RX_Init+0
;usart_test.c,8 :: 		UART_Write('U');
	MOVLW      85
	MOVWF      FARG_UART_Write_Data+0
	CALL       _UART_Write+0
;usart_test.c,9 :: 		UART_Write('A');
	MOVLW      65
	MOVWF      FARG_UART_Write_Data+0
	CALL       _UART_Write+0
;usart_test.c,10 :: 		UART_Write('R');
	MOVLW      82
	MOVWF      FARG_UART_Write_Data+0
	CALL       _UART_Write+0
;usart_test.c,11 :: 		UART_Write('T');
	MOVLW      84
	MOVWF      FARG_UART_Write_Data+0
	CALL       _UART_Write+0
;usart_test.c,12 :: 		UART_Write(' ');
	MOVLW      32
	MOVWF      FARG_UART_Write_Data+0
	CALL       _UART_Write+0
;usart_test.c,13 :: 		UART_Write('O');
	MOVLW      79
	MOVWF      FARG_UART_Write_Data+0
	CALL       _UART_Write+0
;usart_test.c,14 :: 		UART_Write('K');
	MOVLW      75
	MOVWF      FARG_UART_Write_Data+0
	CALL       _UART_Write+0
;usart_test.c,15 :: 		}
L_end_usart_test_run:
	RETURN
; end of _usart_test_run
