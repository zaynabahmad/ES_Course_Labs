
_EXTI_vEnableGlobalInterrupts:

;exti_service.c,5 :: 		void EXTI_vEnableGlobalInterrupts(void) {
;exti_service.c,7 :: 		*((volatile uint8*)0x0B) |= (1 << 7);
	BSF        11, 7
;exti_service.c,8 :: 		}
L_end_EXTI_vEnableGlobalInterrupts:
	RETURN
; end of _EXTI_vEnableGlobalInterrupts

_EXTI_vDisableGlobalInterrupts:

;exti_service.c,10 :: 		void EXTI_vDisableGlobalInterrupts(void) {
;exti_service.c,12 :: 		*((volatile uint8*)0x0B) &= ~(1 << 7);
	BCF        11, 7
;exti_service.c,13 :: 		}
L_end_EXTI_vDisableGlobalInterrupts:
	RETURN
; end of _EXTI_vDisableGlobalInterrupts
