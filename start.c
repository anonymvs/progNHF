#include <stdio.h>
#include <stdlib.h>
#include "header.h"

// Be�r a state v�ltoz�ba egy 1-est azoknak a sejteknek amiknek majd meg kell halniuk.
void state ( palya *p, cells *q) {
    int i;
    for(i=0; i<q->meret; i++) {
        if (test_death(p, q, i) < 2 || test_death(p, q, i) > 3) {
            q->pointer[i].state = 1;
        }
    }
}

//A szimul�ci� motorj�t k�pez� algoritmus.
void round( palya *p, cells *q, int ism, int osszegint, int szorzatint) {
    int i, j, n, before, k, time;
    before = db(p);
    system("cls");
    if (osszeg(p) != osszegint && szorzat(p) != szorzatint) {
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
    if (osszeg(p) != osszegint && szorzat(p) != szorzatint)
        for (time=0; time<50000000; time++);
    if(db(p) == 0) {
        printf("\n --- LEFUTOTT--- \n");
    } else {
        if (before == db(p)) {
            ism++;
            osszegint = osszeg(p);
            szorzatint = szorzat(p);
            if (ism > 40)
                printf("\n --- LEFUTOTT --- \n");
            else
                round(p, q, ism, osszegint, szorzatint);
        } else {
            //ism=0;
            round(p, q, ism, osszegint, szorzatint);
        }
    }
}

//A szimul�ci� motorj�t k�pz� algoritmus, rekurzi� n�lk�l.
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

//Megsz�molja h�ny darab egyes van a p�ly�n.
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

//Meg�li a sejteket amik meg vannak jel�lve.
void verdun (palya *p, cells *q, int n) {
    if (q->pointer[n].state == 1)
        p->palya[q->pointer[n].y][q->pointer[n].x] = 0;
}

//Megn�zi, hogy egy sejtnek h�ny szomsz�dja van a list�b�l.
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

//Megn�zi, hogy egy pontnak a p�ly�n h�ny szomsz�dja van.
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

//�sszeadja a p�ly�n tal�lhat� sejtek koordin�t�it.
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

//�sszeszorozza a p�ly�n tal�lhat� sejtek koordin�t�it.
int szorzat(palya *p) {
        int i, j, szorzat=0;
    for(i=0; i < p->meret.y; i++) {
        for (j=0; j < p->meret.x; j++) {
            if(p->palya[i][j] == 1)
                szorzat = i * j;
        }
    }
    return szorzat;
}


