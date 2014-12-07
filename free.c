#include <stdio.h>
#include <stdlib.h>
#include "header.h"

//Felszabadítja a dinamikus listát ahol a sejtek koordinátáit tároltam.
void felsz_cella(cells *p) {
    free(p->pointer);
}

//Felszabadítja a pályát.
void felsz(palya *p) {
    int i;
    for (i=0; i < p->meret.y; i++) {
        free(p->palya[i]);
    }
    free(p->palya);
}
