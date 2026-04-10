#ifndef COMPILER_COMPAT_H
#define COMPILER_COMPAT_H

/* If compiled with XC8, __XC8 is automatically defined.
   Otherwise, it defaults to MikroC syntax.
 */
#ifdef __XC8
    #define GLOBAL_INTERRUPT() void __interrupt() ISR(void)
#else
    #define GLOBAL_INTERRUPT() void interrupt()
#endif

#endif
