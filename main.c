#include <stdio.h>
#include <stdlib.h>

// men�t vez�rl� enum
typedef enum menu_item {
    meret,
    kezdo,
    betolt,
    start,
    kilepes
} menu_item;

// elemek koordin�t�i
typedef struct koord {
    int x,y;
} koord ;

// strukt�ra ami megadja a j�t�kt�r kiterjed�s�t x, �s y koordin�t�kban amelyek jelenleg "sor" �s "oszlop" n�vvel vannak ell�tva
typedef struct terulet {
    int x, y;
} terulet;


// a ter�let alapj�n l�trehoz egy k�tdimenzi�s dinamikus t�mb�t
typedef struct palya {
    terulet meret;
    int **palya;
} palya;

typedef struct cells {
    int meret;
    koord *pointer;
} cells;

// lefoglalja a p�lya ter�let�t, �s visszat�r egy pointerrel
void foglal ( palya *p) {
    int **uj, i;
    uj = (int**) malloc(p->meret.y * sizeof(int*));
    for (i=0; i < p->meret.y; i++) {
        uj[i] = (int*) malloc(p->meret.x * sizeof(int));
    }
    p->palya = uj;
};

//kinull�zza a ter�letet
void nullaz ( palya *p ) {
    int n, m;
    for (n=0; n < p->meret.y; n++) {
        for (m=0; m < p->meret.x; m++) {
            p->palya[n][m] = 0;
        }
    }
}

//felhaszn�l�t�l fogad koordin�t�kat
void megad (palya *p) {
    int x, y;
    printf("Irja be a kivant koordinatakat enterekkel elvalasztva.\n Megszakitas a (0;0) koordinataval\n");
    while(x != 0 ) {
        printf("x, y:");
        scanf("%d\n%d", &x, &y);
        if (x != 0 && y != 0) {
            p->palya[y-1][x-1] = 1;
        }
        printf("--- megadva ---");
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

void die ( palya *p, cells *q) {

}

void start( palya *p, cells *q) {

}

void test ( palya *p, cells *q) {
    int i, j, k, l, db;
    for(i=1; i<(p->meret.y - 1) ; i++) {
        for(j=1; j<(p->meret.x - 1) ; j++) {
            db= 0;

        }
    }
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
    terulet jatekter;
    printf("--- MENU ---\n"
                "0 - Jatekter meretenek megadasa\n"
                "1 - Kezdo koordinatak megadasa\n"
                "2 - Kezdo allapot betoltese fajlbol\n"
                "3 - Szimulacio ind�tasa...\n"
                "4 - Kilepes...\n");
    scanf("%d", &r);
    while (r != kilepes ) {
        switch (r) {
        case meret :
            printf("Mekkora legyen a jatekter?\n");
            scanf("%d\n%d", &jatekter.x, &jatekter.y);
            p->meret.x = jatekter.x;
            p->meret.y = jatekter.y;
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
            break;
        case betolt:
            printf("Fajlbol betoltom az altalam megadott alapallapotot.");
            break;
        case start :
            printf("Ind�t�s...");
            break;
        }
        printf("Hogyan tovabb?\n"
                   "0 - Jatekter meretenek megadasa\n"
                   "1 - Kezdo koordinatak megadasa\n"
                   "2 - Kezdo allapot betoltese fajlbol\n"
                   "3 - Szimulacio ind�tasa...\n"
                   "4 - Kilepes...\n");
        scanf("%d", &r);
    }
}

int main()
{
    int i, j;
    terulet jatekter;
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
