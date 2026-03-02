typedef unsigned char uint8;
typedef void (*InterruptHandler)(void);

#define SET_BIT(REG,BIT)  ((REG) |=  (1U << (BIT)))
#define CLR_BIT(REG,BIT)  ((REG) &= ~(1U << (BIT)))
#define TOG_BIT(REG,BIT)  ((REG) ^=  (1U << (BIT)))
#define GET_BIT(REG,BIT)  (((REG) >> (BIT)) & 1U)

#define INT0_EDGE       0U
#define DEBOUNCE_COUNT  1000U
#define LED  0U

/* --- MCAL ----------------------------------------------- */
static InterruptHandler INT0_Callback = 0;

void EXT_INT0_SetEdge(uint8 edge)           { edge ? SET_BIT(OPTION_REG,6) : CLR_BIT(OPTION_REG,6); }
void EXT_INT0_SetCallback(InterruptHandler ptr) { if(ptr) INT0_Callback = ptr; }
void EXT_INT0_Init(void)    { SET_BIT(TRISB,0); CLR_BIT(INTCON,1); EXT_INT0_SetEdge(INT0_EDGE); }
void EXT_INT0_Enable(void)  { CLR_BIT(INTCON,1); SET_BIT(INTCON,4); SET_BIT(INTCON,7); }
void EXT_INT0_Disable(void) { CLR_BIT(INTCON,4); CLR_BIT(INTCON,1); }

void interrupt() {
    unsigned int d;
    if (GET_BIT(INTCON, 1)) {
        CLR_BIT(INTCON, 1);
        d = DEBOUNCE_COUNT;
        while(d--);
        if (!GET_BIT(PORTB, 0) && INT0_Callback) INT0_Callback();
    }
}

/* --- HAL ------------------------------------------------ */
void LED_Init(void)   { CLR_BIT(TRISC, LED); CLR_BIT(PORTC, LED); }
void LED_Toggle(void) { TOG_BIT(PORTC, LED); }
void SWITCH_Init(uint8 pin) { SET_BIT(TRISB, pin); CLR_BIT(OPTION_REG, 7); }

/* --- Application ---------------------------------------- */
void INT0_Handler(void) { LED_Toggle(); }

void main(void) {
    LED_Init();
    SWITCH_Init(0);
    EXT_INT0_Init();
    EXT_INT0_SetCallback(INT0_Handler);
    EXT_INT0_Enable();
    while(1) { }
}