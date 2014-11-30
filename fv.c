#include <stdio.h>
#include <stdlib.h>
#include "header.h"

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

//felhasználótól fogad koordinátákat
void megad (palya *p) {
    int x, y;
    printf("Irja be a kivant koordinatakat enterekkel elvalasztva.\n Megszakitas a (0;0) koordinataval\n");
    while(x != 0 ) {
        printf("x, y:\n");
        scanf("%d\n%d", &x, &y);
        if (x != 0 && y != 0) {
            if (x == p->meret.y || y == p->meret.x || x == 1 || y == 1) {
                p->palya[y-1][x-1] = 0;
            } else {
                p->palya[y-1][x-1] = 1;
            }
        }
        printf("--- megadva ---\n");
    }
}

void sejtek ( palya *p, cells *q) {
    int i, j, k=0, n=0;
    koord *uj;
    for(i=0; i<p->meret.y; i++) {
        for(j=0; j<p->meret.x; j++) {
            if (p->palya[i][j] == 1) {
                n++;
            }
        }
    }
    q->meret = n;
    uj = (koord*) malloc(n*sizeof(koord));
    for(i=0; i<p->meret.y; i++) {
        for(j=0; j<p->meret.x; j++) {
            if (p->palya[i][j] == 1) {
                uj[k].x = j;
                uj[k].y = i;
                k++;
            }
        }
    }
    q->pointer = uj;
    for(i=0; i<n ; i++) {
        printf("(%d;%d)\n", q->pointer[i].x, q->pointer[i].y);
    }
}
/*
void die ( palya *p, cells *q) {
    return 0;
}

void start( palya *p, cells *q) {
    return 0;
}
*/
int test ( palya *p, cells *q, int i) {
    int j, k, db=0;
    for(j= -1; j<=1; j++) {
        for (k= -1; k<=1; k++) {
            if (p->palya[(q->pointer[i].y)+j][(q->pointer[i].x)+k] == 1)
                db++;
            }
        }
    return (db-1);
}

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
