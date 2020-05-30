#include "detector.h"

int state = A;
unsigned char Detector (unsigned char in) {
    switch (state) {
        case A : if ( in) state = B; else state = A; break;
        case B : if ( in) state = B; else state = C; break;
        case C : if ( in) state = D; else state = A; break;
        case D : if ( in) state = B; else state = E; break;
        case E : if ( in) state = D; else state = A;
    }
    if (state == E) return 1; else return 0;
}

