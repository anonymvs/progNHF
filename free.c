#include <stdio.h>
#include <stdlib.h>
#include "header.h"

//Felszabad�tja a dinamikus list�t ahol a sejtek koordin�t�it t�roltam.
void felsz_cella(cells *p) {
    free(p->pointer);
}

//Felszabad�tja a p�ly�t.
void felsz(palya *p) {
    int i;
    for (i=0; i < p->meret.y; i++) {
        free(p->palya[i]);
    }
    free(p->palya);
}
