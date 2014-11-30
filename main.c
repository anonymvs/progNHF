#include <stdio.h>
#include <stdlib.h>


// menüt vezérlõ enum
typedef enum menu_item {
    meret,
    kezdo,
    betolt,
    start,
    kilepes
} menu_item;

// elemek koordinátái
typedef struct koord {
    int x,y;
} koord ;

// a terület alapján létrehoz egy kétdimenziós dinamikus tömböt
typedef struct palya {
    koord meret;
    int **palya;
} palya;

typedef struct cells {
    int state; //két állás 1 meghal 0 él
    int meret;
    koord *pointer;
} cells;

// lefoglalja a pálya területét, és visszatér egy pointerrel
void foglal ( palya *p) {
    int **uj, i;
    uj = (int**) malloc(p->meret.y * sizeof(int*));
    for (i=0; i < p->meret.y; i++) {
        uj[i] = (int*) malloc(p->meret.x * sizeof(int));
    }
    p->palya = uj;
};

//kinullázza a területet
void nullaz ( palya *p ) {
    int n, m;
    for (n=0; n < p->meret.y; n++) {
        for (m=0; m < p->meret.x; m++) {
            p->palya[n][m] = 0;
        }
    }
}

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

void menu( palya *p, cells *q ) {
    int i, j;
    menu_item r;
    koord jatekter;
    printf("--- MENU ---\n"
                "0 - Jatekter meretenek megadasa\n"
                "1 - Kezdo koordinatak megadasa\n"
                "2 - Kezdo allapot betoltese fajlbol\n"
                "3 - Szimulacio indítasa...\n"
                "4 - Kilepes...\n");
    scanf("%d", &r);
    while (r != kilepes ) {
        switch (r) {
        case meret :
            printf("Mekkora legyen a jatekter?\n");
            scanf("%d\n%d", &jatekter.x, &jatekter.y);
            p->meret.x = jatekter.x+1;
            p->meret.y = jatekter.y+1;
            printf("----- x: %d", p->meret.x);
            foglal(p);
            nullaz(p);
            printf("jatekter lefoglalva es nullazva\n");
            for(i=0; i<p->meret.y; i++) {
                for(j=0; j<p->meret.x; j++) {
                    printf("%d", p->palya[i][j]);
                }
                printf("\n");
            }
            break;
        case kezdo :
            printf("A kezdo pontok elhelyezese:");
            megad(p);
            printf("Kezdoallapot:\n");
            for(i=0; i < p->meret.y; i++) {
                for (j=0; j < p->meret.x; j++) {
                    printf("%d", p->palya[i][j] );
                }
                printf("\n");
            }
            sejtek(p, q);
            for (i=0; i<q->meret; i++) {
                printf("(%d;%d) -- ", q->pointer[i].x, q->pointer[i].y);
                printf("db: %d\n", test(p, q, i));
            }
            break;
        case betolt:
            printf("Fajlbol betoltom az altalam megadott alapallapotot.");
            break;
        case start :
            printf("Indítás...");
            break;
        }
        printf("Hogyan tovabb?\n"
                   "0 - Jatekter meretenek megadasa\n"
                   "1 - Kezdo koordinatak megadasa\n"
                   "2 - Kezdo allapot betoltese fajlbol\n"
                   "3 - Szimulacio indítasa...\n"
                   "4 - Kilepes...\n");
        scanf("%d", &r);
    }
}

int main()
{
    int i, j;
    koord jatekter;
    palya eletter;
    cells sejt;

    menu(&eletter, &sejt);
    for (i=0; i<eletter.meret.y; i++) {
        for (j=0; j<eletter.meret.x; j++) {
            printf(" %d ", eletter.palya[i][j]);
        }
        printf("\n");
    }

    felsz(&eletter);
    return 0;
}
