#include <stdio.h>
#include <stdlib.h>

// elemek koordinátái
typedef struct koord {
    int x,y;
} koord ;

// struktúra ami megadja a játéktér kiterjedését x, és y koordinátákban amelyek jelenleg "sor" és "oszlop" névvel vannak ellátva
typedef struct terulet {
    int x, y;
} terulet;

// menüt vezérlõ enum
typedef enum menu_item {
    meret,
    kezdo,
    betolt,
    start,
    kilepes
} menu_item;

// a terület alapján létrehoz egy kétdimenziós dinamikus tömböt
typedef struct palya {
    terulet meret;
    int **palya;
} palya;

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

void megad (palya *p) {
    int i;
    koord r;
    printf("Irja be a kivant koordinatakat enterekkel elvalasztva.(kilepeshez adjon meg koordinataknak x-et)");
    while(r.x != 'x' && r.y != 'x') {
        printf("x:");
        scanf("%d\n", r.x);
        printf("y:");
        scanf("%d\n", r.y);
        p->palya[r.y][r.x] = 1;
    }
}
/*void test () {
    int i;
    for (i=0; )
}*/

void felsz(palya *p) {
    int i;
    for (i=0; i < p->meret.y; i++) {
        free(p->palya[i]);
    }
    free(p->palya);
}

void menu( palya *p ) {
    menu_item r;
    terulet jatekter;
    printf("--- MENU ---\n"
                "0 - Jatekter meretenek megadasa\n"
                "1 - Kezdo koordinatak megadasa\n"
                "2 - Kezdo allapot betoltese fajlbol\n"
                "3 - Szimulacio indítasa...\n"
                "4 - Kilepes...\n");
    scanf("%d\n", &r);
    while (r != 4 ) {
        switch (r) {
        case meret :
            printf("Mekkora legyen a jatekter?\n");
            scanf("%d\n%d", &jatekter.x, &jatekter.y);
            p->meret.x = jatekter.x;
            p->meret.y = jatekter.y;
            foglal(&p);
            nullaz(&p);
            break;
        case kezdo :
            printf("A kezdo pontok elhelyezese:");
            megad(&p);
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
    terulet jatekter;
    palya eletter;

    menu(&eletter);
    for (i=0; i<eletter.meret.y; i++) {
        for (j=0; j<eletter.meret.x; j++) {
            printf(" %d ", eletter.palya[i][j]);
        }
        printf("\n");
    }

    felsz(&eletter);
    return 0;
}
