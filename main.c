#include <stdio.h>
#include <stdlib.h>

// elemek koordin�t�i
typedef struct coord {
    int x,y;
} coord ;

// strukt�ra ami megadja a j�t�kt�r kiterjed�s�t x, �s y koordin�t�kban amelyek jelenleg "sor" �s "oszlop" n�vvel vannak ell�tva
typedef struct terulet {
    int x, y;
} terulet;

// men�t vez�rl� enum
typedef enum menu {
    meret,
    kezdo,
    betolt,
    start
} menu;

// a ter�let alapj�n l�trehoz egy k�tdimenzi�s dinamikus t�mb�t
typedef struct palya {
    terulet meret;
    int **palya;
} palya;

// lefoglalja a p�lya ter�let�t, �s visszat�r egy pointerrel
void foglal ( palya *p) {
    int **uj, i;
    uj = (int**) malloc(p->meret.y * sizeof(int*));
    for (i=0; i < p->meret.x; i++) {
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

/*void test () {
    int i;
    for (i=0; )
}*/


int main()
{
    int i, n;
    menu elso;
    terulet jatekter;
    palya ures;


    printf("Hello playaaaa!\n");
    scanf("%d", &elso);
    switch (elso) {
        case meret :
            printf("Mekkora legyen a jatekter?\n");
            scanf("%d\n%d", &jatekter.x, &jatekter.y);
            ures.meret.x = jatekter.x;
            ures.meret.y = jatekter.y;
            foglal(&ures);
            nullaz(&ures);
            for (i=0; i< ures.meret.y; i++) {
                for (n=0; n<ures.meret.x; n++) {
                    printf("%d", ures.palya[i][n]);
                }
                printf("\n");
            }
            break;
        case kezdo :
            printf("A kezdo pontok elhelyezese:");
            break;
        case betolt:
            printf("Fajlbol betoltom az altalam megadott alapallapotot.");
            break;
        case start :
            printf("Ind�t�s...");
            break;
    }

    return 0;
}
