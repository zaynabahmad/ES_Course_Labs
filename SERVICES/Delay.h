#ifndef DELAY_H
#define DELAY_H

static inline void Delay_ms(unsigned int ms) {
    volatile unsigned int i, j;
    for(i = 0; i < ms; i++) {
        for(j = 0; j < 120; j++) {

        }
    }
}

#endif