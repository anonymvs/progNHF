#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void menu( palya *p, cells *q ) {
    int i, j, d, ism, osszegint;
    menu_item r;
    koord jatekter;
    printf("--- MENU ---\n"
                "0 - Jatekter meretenek megadasa\n"
                "1 - Kezdo koordinatak megadasa\n"
                "2 - Kezdo allapot betoltese fajlbol\n"
                "3 - Szimulacio inditasa...\n"
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
                printf("db: %d\n", test_death(p, q, i));
            }
            break;
        case betolt:
            printf("Fajlbol betoltom az altalam megadott alapallapotot.");
            break;
        case start :
            printf("Automatikus lefutas: 0\nLeptetes: 1\n");
            scanf("%d\n", &d);
            if (d == 1) {
                printf("Barmelyik egesz szam es egy enter lenyomasara tudsz leptetni.\n");
                printf("A 0 lenyomasaval tudsz kilepni a ciklusbol.\n");
                ism = 0;
                while (d != 0) {
                    leptet(p, q);
                    scanf("%d\n", &d);
                }
            } else {
                ism= 0;
                osszegint = 0;
                round(p, q, ism, osszegint);
            }
            for(i=0; i < p->meret.y; i++) {
                for (j=0; j < p->meret.x; j++) {
                    printf("%d", p->palya[i][j] );
            }
            printf("\n");
            }
            printf("\n");
            printf("\n\n --- %d --- \n", ism);
            felsz(p);
                break;
        case kilepes :
            printf("That's all folks!");
            break;
        }
        if (r != 4) {
            printf("Hogyan tovabb?\n"
                   "0 - Jatekter meretenek megadasa\n"
                   "1 - Kezdo koordinatak megadasa\n"
                   "2 - Kezdo allapot betoltese fajlbol\n"
                   "3 - Szimulacio inditasa...\n"
                   "4 - Kilepes...\n");
            scanf("%d", &r);
        }
    }
}
