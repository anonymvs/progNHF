#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void megad (palya *p) {
    int x, y;
    printf("\nIrja be a kivant koordinatakat enterekkel elvalasztva.\nMegszakitas a (0;0) koordinataval\n");
    while(x != 0 ) {
        printf("x, y:\n");
        scanf("%d\n%d", &x, &y);
        if (x != 0 && y != 0) {
            if (x <= p->meret.y || y <= p->meret.x) {
                if (x == p->meret.y || y == p->meret.x || x == 1 || y == 1) {
                    p->palya[y-1][x-1] = 0;
                } else {
                    p->palya[y-1][x-1] = 1;
                }
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
                uj[k].state = 0;
                k++;
            }
        }
    }
    q->pointer = uj;
    //for(i=0; i<n ; i++) {
    //    printf("(%d;%d)\n", q->pointer[i].x, q->pointer[i].y);
    //}
}

void randomkoord(palya *p, int top) {
    int t, x, y, max=0, n=0, i, j;
    srand((int) time(&t));
    //max = (p->meret.x * p->meret.y)/2;
    while ( db(p) != top) {
        x = rand() % (p->meret.x-2);
        y = rand() % (p->meret.y-2);
        p->palya[y+1][x+1] = 1;
    }
    for(i=0; i < p->meret.y; i++) {
        for (j=0; j < p->meret.x; j++) {
            printf("%d", p->palya[i][j] );
        }
        printf("\n");
    }
    printf("\n");

    printf("\n--- KOORDINATAK BEALLITVA ---\n");
}
