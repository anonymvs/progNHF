#include <stdio.h>
#include <stdlib.h>
#include "header.h"

// Kinullázza a pályát amit korábban lefoglaltam.
void nullaz ( palya *p ) {
    int n, m;
    for (n=0; n < p->meret.y; n++) {
        for (m=0; m < p->meret.x; m++) {
            p->palya[n][m] = 0;
        }
    }
}

// lefoglalja a pálya területét, és visszatér egy pointerrel
void foglal ( palya *p) {
    int **uj, i;
    uj = (int**) malloc(p->meret.y * sizeof(int*));
    for (i=0; i < p->meret.y; i++) {
        uj[i] = (int*) malloc(p->meret.x * sizeof(int));
    }
    p->palya = uj;
};
