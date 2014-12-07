#include <stdio.h>
#include <stdlib.h>
#include "header.h"


void fajlbair(palya *p, cells *q) {
    int i, j;
    FILE *f1test, *f2koord;
    f1test = fopen("lementett.txt", "wt");
    for(i=0; i < p->meret.y; i++) {
        for (j=0; j < p->meret.x; j++) {
            fprintf(f1test, "%d ", p->palya[i][j]);
        }
        fprintf(f1test, "\n");
    }
    f2koord = fopen("lementettkoord.txt", "wt");
    for (i=0; i<q->meret; i++) {
        fprintf(f2koord, "%d %d\n", q->pointer[i].x, q->pointer[i].y);
    }
    fclose(f1test);
    fclose(f2koord);
}

void fajlbeolv10x10 (palya *p) {
    int i, j, d, meret=15;
    FILE *f1test;
    koord lista[15];
    f1test = fopen("koord10x10.txt", "rt");
    for(i=0; i<15; i++) {
        fscanf(f1test, "%d %d\n", &lista[i].x, &lista[i].y );
    }
    /*
    for (i=0; i<15; i++) {
        printf("(%d;%d)\n", lista[i].x, lista[i].y);
    }
    */
    system("cls");
    koordbeir(p, &lista, meret);
    for(i=0; i < p->meret.y; i++) {
        for (j=0; j < p->meret.x; j++) {
            printf("%d", p->palya[i][j] );
        }
        printf("\n");
    }
    printf("\n");
    fclose(f1test);
}

void fajlbeolv20x20 (palya *p) {
    int i, j, d, meret=30;
    FILE *f1test;
    koord lista[30];
    f1test = fopen("koord20x20.txt", "rt");
    for(i=0; i<30; i++) {
        fscanf(f1test, "%d %d\n", &lista[i].x, &lista[i].y );
    }
    /*
    for (i=0; i<30; i++) {
        printf("(%d;%d)\n", lista[i].x, lista[i].y);
    }
    */
    system("cls");
    for(i=0; i < p->meret.y; i++) {
        for (j=0; j < p->meret.x; j++) {
            printf("%d", p->palya[i][j] );
        }
        printf("\n");
    }
    printf("\n");
    koordbeir(p, &lista, meret);
    fclose(f1test);
}

void fajlbeolv60x15 (palya *p) {
    int i, j, d, meret=120;
    FILE *f1test;
    koord lista[120];
    f1test = fopen("koord60x15.txt", "rt");
    for(i=0; i<120; i++) {
        fscanf(f1test, "%d %d\n", &lista[i].x, &lista[i].y );
    }
    /*
    for (i=0; i<120; i++) {
        printf("(%d;%d)\n", lista[i].x, lista[i].y);
    }
    */
    system("cls");
    koordbeir(p, &lista, meret);
    for(i=0; i < p->meret.y; i++) {
        for (j=0; j < p->meret.x; j++) {
            printf("%d", p->palya[i][j] );
        }
        printf("\n");
    }
    printf("\n");
    fclose(f1test);
}

void koordbeir(palya *p, koord *q, int meret) {
    int n;
    for(n=0; n<meret; n++) {
        p->palya[q[n].y][q[n].x] = 1;
    }

}
