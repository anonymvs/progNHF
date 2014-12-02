#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void felsz_cella(cells *p) {
    free(p->pointer);
}

void felsz(palya *p) {
    int i;
    for (i=0; i < p->meret.y; i++) {
        free(p->palya[i]);
    }
    free(p->palya);
}
