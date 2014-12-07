#include <stdio.h>
#include <stdlib.h>
#include "header.h"


//felhasználótól fogad koordinátákat
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

void state ( palya *p, cells *q) {
    int i;
    for(i=0; i<q->meret; i++) {
        if (test_death(p, q, i) < 2 || test_death(p, q, i) > 3) {
            q->pointer[i].state = 1;
        }
    }
}

void round( palya *p, cells *q, int ism, int osszegint) {
    int i, j, n, before, k, time;
    before = db(p);
    system("cls");
    if (osszeg(p) != osszegint) {
        for(i=0; i < p->meret.y; i++) {
            for (j=0; j < p->meret.x; j++) {
                printf("%d", p->palya[i][j] );
            }
            printf("\n");
        }
        printf("\n");
    }
    sejtek(p, q);
    state(p, q);
    /*
    for (i=0; i<q->meret; i++) {
        printf("(%d;%d) -- ", q->pointer[i].x, q->pointer[i].y);
        printf("db: %d -- ", test_death(p, q, i));
        printf("state: %d\n", q->pointer[i].state);
    }
    */
    for(i=1; i < p->meret.y-1; i++) {
        for(j=1; j < p->meret.x-1; j++) {
            if (test_born(p, i, j) == 3){
                p->palya[i][j]= 1;
            }
        }
    }
    for (n=0; n<q->meret; n++) {
        verdun(p, q, n);
    }
    felsz_cella(q);
    //system("cls");
    /*
    if (osszeg(p) != osszegint) {
        for(i=0; i < p->meret.y; i++) {
            for (j=0; j < p->meret.x; j++) {
                printf(" ");
            }
            printf("\n");
        }
        printf("\n");
    }
    */
    //printf("\n --- db: %d --- \n", db(p));
    if (osszeg(p) != osszegint)
        for (time=0; time<50000000; time++);
    if(db(p) == 0) {
        printf("\n --- LEFUTOTT--- \n");
    } else {
        if (before == db(p)) {
            ism++;
            osszegint = osszeg(p);
            if (ism > 100)
                printf("\n --- LEFUTOTT --- \n");
            else
                round(p, q, ism, osszegint);
        } else {
            //ism=0;
            round(p, q, ism, osszegint);
        }
    }
}

void leptet( palya *p, cells *q) {
    int i, j, n, ism, before;
    system("cls");
    before = db(p);
    for(i=0; i < p->meret.y; i++) {
        for (j=0; j < p->meret.x; j++) {
            printf("%d", p->palya[i][j] );
        }
        printf("\n");
    }
    sejtek(p, q);
    state(p, q);
    for(i=1; i < p->meret.y-1; i++) {
        for(j=1; j < p->meret.x-1; j++) {
            if (test_born(p, i, j) == 3){
                p->palya[i][j]= 1;
            }
        }
    }
    for (n=0; n<q->meret; n++) {
        verdun(p, q, n);
    }
    felsz_cella(q);
    /*
    for(i=0; i < p->meret.y; i++) {
        for (j=0; j < p->meret.x; j++) {
            printf("%d", p->palya[i][j] );
        }
        printf("\n");
    }
    printf("\n");
    */
    if(db(p) == 0) {
        printf("\n --- LEFUTOTT--- \n");
    } else {
        if (before == db(p)) {
            ism++;
            if (ism > 20)
                printf("\n --- LEFUTOTT --- \n");
        }
    }
}

int db (palya *p) {
    int i, j, db=0;
    for(i=0; i < p->meret.y; i++) {
        for (j=0; j < p->meret.x; j++) {
            if(p->palya[i][j] == 1)
                db++;
        }
    }
    return db;
}

void verdun (palya *p, cells *q, int n) {
    if (q->pointer[n].state == 1)
        p->palya[q->pointer[n].y][q->pointer[n].x] = 0;
}

int test_death ( palya *p, cells *q, int i) {
    int j, k, db=0;
    for(j= -1; j<=1; j++) {
        for (k= -1; k<=1; k++) {
            if (p->palya[(q->pointer[i].y)+j][(q->pointer[i].x)+k] == 1)
                db++;
            }
        }
    return (db-1);
}

int test_born( palya *p, int i, int j) {
    int db=0, a, b;
    if ( p->palya[i][j] == 0 ) {
        for(a= -1; a<=1; a++) {
            for (b= -1; b<=1; b++) {
                if (p->palya[i+a][j+b] == 1)
                    db++;
            }
        }
    }
    return db;
}

int osszeg(palya *p) {
    int i, j, osszeg=0;
    for(i=0; i < p->meret.y; i++) {
        for (j=0; j < p->meret.x; j++) {
            if(p->palya[i][j] == 1)
                osszeg = i + j;
        }
    }
    return osszeg;
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
