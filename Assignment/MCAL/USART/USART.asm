
_UART_RX_Init:

;USART.c,14 :: 		void UART_RX_Init(void)
;USART.c,17 :: 		SET_BIT(TXSTA , BRGH);      // High Speed Mode
	BSF        152, 2
;USART.c,19 :: 		SPBRG = 25;                 // 9600 Baud
	MOVLW      25
	MOVWF      153
;USART.c,21 :: 		CLR_BIT(TXSTA , SYNC);      // Asynchronous Mode
	MOVLW      239
	ANDWF      152, 1
;USART.c,23 :: 		SET_BIT(RCSTA , SPEN);      // Enable Serial Port
	BSF        24, 7
;USART.c,25 :: 		SET_BIT(RCSTA , CREN);      // Continuous Receive
	BSF        24, 4
;USART.c,27 :: 		SET_BIT(PIE1 , RCIE);       // Enable UART RX Interrupt
	BSF        140, 5
;USART.c,29 :: 		SET_BIT(INTCON , PEIE);     // Peripheral Interrupt Enable
	BSF        INTCON+0, 6
;USART.c,30 :: 		SET_BIT(INTCON , GIE);      // Global Interrupt Enable
	BSF        INTCON+0, 7
;USART.c,31 :: 		}
L_end_UART_RX_Init:
	RETURN
; end of _UART_RX_Init

_UART_TX_Init:

;USART.c,37 :: 		void UART_TX_Init(void)
;USART.c,40 :: 		SET_BIT(TXSTA , BRGH);      // High Speed
	BSF        152, 2
;USART.c,42 :: 		SPBRG = 25;                 // Baud Rate
	MOVLW      25
	MOVWF      153
;USART.c,44 :: 		CLR_BIT(TXSTA , SYNC);      // Asynchronous Mode
	MOVLW      239
	ANDWF      152, 1
;USART.c,46 :: 		SET_BIT(RCSTA , SPEN);      // Enable Serial Port
	BSF        24, 7
;USART.c,48 :: 		SET_BIT(TXSTA , TXEN);      // Enable Transmission
	BSF        152, 5
;USART.c,49 :: 		}
L_end_UART_TX_Init:
	RETURN
; end of _UART_TX_Init

_UART_Write:

;USART.c,55 :: 		void UART_Write(u8 Data)
;USART.c,58 :: 		while(!GET_BIT(TXSTA , TRMT));   // Wait until TX empty
L_UART_Write0:
	MOVF       152, 0
	MOVWF      R1+0
	RRF        R1+0, 1
	BCF        R1+0, 7
	BTFSC      R1+0, 0
	GOTO       L_UART_Write1
	GOTO       L_UART_Write0
L_UART_Write1:
;USART.c,60 :: 		TXREG = Data;
	MOVF       FARG_UART_Write_Data+0, 0
	MOVWF      25
;USART.c,61 :: 		}
L_end_UART_Write:
	RETURN
; end of _UART_Write

_UART_Read:

;USART.c,67 :: 		u8 UART_Read(void)
;USART.c,70 :: 		while(!GET_BIT(PIR1 , RCIF));    // Wait for data
L_UART_Read2:
	MOVLW      5
	MOVWF      R0+0
	MOVF       12, 0
	MOVWF      R1+0
	MOVF       R0+0, 0
L__UART_Read10:
	BTFSC      STATUS+0, 2
	GOTO       L__UART_Read11
	RRF        R1+0, 1
	BCF        R1+0, 7
	ADDLW      255
	GOTO       L__UART_Read10
L__UART_Read11:
	BTFSC      R1+0, 0
	GOTO       L_UART_Read3
	GOTO       L_UART_Read2
L_UART_Read3:
;USART.c,72 :: 		return RCREG;
	MOVF       26, 0
	MOVWF      R0+0
;USART.c,73 :: 		}
L_end_UART_Read:
	RETURN
; end of _UART_Read

_UART_TX_Empty:

;USART.c,79 :: 		u8 UART_TX_Empty(void)
;USART.c,82 :: 		return GET_BIT(TXSTA , TRMT);
	MOVF       152, 0
	MOVWF      R0+0
	RRF        R0+0, 1
	BCF        R0+0, 7
	MOVLW      1
	ANDWF      R0+0, 1
;USART.c,83 :: 		}
L_end_UART_TX_Empty:
	RETURN
; end of _UART_TX_Empty

_UART_SetCallback:

;USART.c,89 :: 		void UART_SetCallback(void (*Callback)(u8))
;USART.c,92 :: 		if(Callback != 0)
	MOVF       FARG_UART_SetCallback_Callback+0, 0
	MOVWF      R1+0
	MOVF       FARG_UART_SetCallback_Callback+1, 0
	MOVWF      R1+1
	MOVF       FARG_UART_SetCallback_Callback+2, 0
	MOVWF      R1+2
	MOVF       FARG_UART_SetCallback_Callback+3, 0
	MOVWF      R1+3
	MOVLW      0
	MOVWF      R0+0
	XORWF      R1+3, 0
	BTFSS      STATUS+0, 2
	GOTO       L__UART_SetCallback14
	MOVF       R0+0, 0
	XORWF      R1+2, 0
	BTFSS      STATUS+0, 2
	GOTO       L__UART_SetCallback14
	MOVF       R0+0, 0
	XORWF      R1+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__UART_SetCallback14
	MOVF       R1+0, 0
	XORLW      0
L__UART_SetCallback14:
	BTFSC      STATUS+0, 2
	GOTO       L_UART_SetCallback4
;USART.c,94 :: 		UART_Callback = Callback;
	MOVF       FARG_UART_SetCallback_Callback+0, 0
	MOVWF      _UART_Callback+0
	MOVF       FARG_UART_SetCallback_Callback+1, 0
	MOVWF      _UART_Callback+1
	MOVF       FARG_UART_SetCallback_Callback+2, 0
	MOVWF      _UART_Callback+2
	MOVF       FARG_UART_SetCallback_Callback+3, 0
;USART.c,95 :: 		}
L_UART_SetCallback4:
;USART.c,97 :: 		}
L_end_UART_SetCallback:
	RETURN
; end of _UART_SetCallback

_UART_ISR:

;USART.c,99 :: 		void UART_ISR(void)
;USART.c,102 :: 		u8 UART_data = RCREG;   //
	MOVF       26, 0
	MOVWF      UART_ISR_UART_data_L0+0
;USART.c,103 :: 		if(UART_Callback != 0)
	MOVF       _UART_Callback+0, 0
	MOVWF      R1+0
	MOVF       _UART_Callback+1, 0
	MOVWF      R1+1
	MOVF       _UART_Callback+2, 0
	MOVWF      R1+2
	MOVF       _UART_Callback+3, 0
	MOVWF      R1+3
	MOVLW      0
	MOVWF      R0+0
	XORWF      R1+3, 0
	BTFSS      STATUS+0, 2
	GOTO       L__UART_ISR16
	MOVF       R0+0, 0
	XORWF      R1+2, 0
	BTFSS      STATUS+0, 2
	GOTO       L__UART_ISR16
	MOVF       R0+0, 0
	XORWF      R1+1, 0
	BTFSS      STATUS+0, 2
	GOTO       L__UART_ISR16
	MOVF       R1+0, 0
	XORLW      0
L__UART_ISR16:
	BTFSC      STATUS+0, 2
	GOTO       L_UART_ISR5
;USART.c,105 :: 		UART_Callback(UART_data);   //
	MOVF       _UART_Callback+2, 0
	MOVWF      FSR
	MOVF       UART_ISR_UART_data_L0+0, 0
	MOVWF      INDF+0
	INCF       FSR, 1
	MOVF       _UART_Callback+0, 0
	MOVWF      ___DoICPAddr+0
	MOVF       _UART_Callback+1, 0
	MOVWF      ___DoICPAddr+1
	CALL       _____DoIFC+0
;USART.c,106 :: 		}
L_UART_ISR5:
;USART.c,108 :: 		}
L_end_UART_ISR:
	RETURN
; end of _UART_ISR
