#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void menu( palya *p, cells *q) {
    int i, j, d, ism, osszegint, szorzatint, kezdoallapot, db;
    menu_item r;
    menu_betolt h;
    koord jatekter;
    printf("--- MENU ---\n"
                "A kezdo pontok elhelyezesehez meg kell adni eloszor a palya meretet.\n\n"
                "0 - Jatekter meretenek megadasa\n"
                "1 - Kezdo koordinatak megadasa\n"
                "2 - Kezdo allapot betoltese fajlbol\n"
                "3 - Szimulacio inditasa...\n"
                "4 - Kilepes...\n"
                "\nA nem veges szimulaciok sem futnak orokke egy ponton le lesznek allitva."
                "\nEz a pont sajnalatos modon nem megvalaszthato.\n");
    while (r != kilepes ) {
        scanf("%d", &r);
        switch (r) {
        case meret :
            printf("\nMekkora legyen a jatekter?\n");
            scanf("%d\n%d", &jatekter.x, &jatekter.y);
            p->meret.x = jatekter.x+1;
            p->meret.y = jatekter.y+1;
            //printf("----- x: %d", p->meret.x);
            foglal(p);
            nullaz(p);
            system("cls");
            for(i=0; i<p->meret.y; i++) {
                for(j=0; j<p->meret.x; j++) {
                    printf("%d", p->palya[i][j]);
                }
                printf("\n");
            }
            printf("--- jatekter lefoglalva es nullazva --- \n\n");
            break;
        case kezdo :
            printf("\nA kezdo pontok elhelyezese:\n");
            printf("0 - Gep altal random elhelyezett kezdopontok.\n"
                   "1 - Kezdopontok felhasznalo altali megadasa\n");
            scanf("%d", &kezdoallapot);
            if (kezdoallapot == 0) {
                printf("\nHany darab sejt legyen a palyan?\n");
                scanf("%d", &db);
                randomkoord(p, db);
            } else {
                megad(p);
                printf("Kezdoallapot:\n");
                for(i=0; i < p->meret.y; i++) {
                    for (j=0; j < p->meret.x; j++) {
                        printf("%d", p->palya[i][j] );
                    }
                    printf("\n");
                }
            }
            sejtek(p, q);
            for (i=0; i<q->meret; i++) {
                printf("(%d;%d) -- ", q->pointer[i].x, q->pointer[i].y);
                printf("db: %d\n", test_death(p, q, i));
            }
            fajlbair(p, q);
            break;
        case betolt:
            printf("\nA keszito altal elore megadott alapallapot betoltese.\n");
            printf("Valaszthat 3 kulonbozo meretu alapallapotbol.\n"
                   "0 - Az elso egy 10x10-es kezdoallapot. (veges)\n"
                   "1 - A masodik egy 20x20-as kezdoallapot. (vegtelen)\n"
                   "2 - A harmadik egy 60x15-os kezdoallapot. (vegtelen)\n"
                   "3 - Vissza a fomenube.\n");
            scanf("%d", &h);
            switch (h) {
            case elso :
                printf("Az elso allapot 10x10-es kezdoallapot:\n");
                p->meret.x = 11;
                p->meret.y = 11;
                foglal(p);
                nullaz(p);
                fajlbeolv10x10(p);
                break;
            case masodik :
                printf("A masodik allapot 20x20-as kezdoallapot:\n");
                p->meret.x = 21;
                p->meret.y = 21;
                foglal(p);
                nullaz(p);
                fajlbeolv20x20(p);
                break;
                case harmadik :
                printf("A harmadik allapot 60x15-os kezdoallapot:\n");
                p->meret.x = 61;
                p->meret.y = 16;
                foglal(p);
                nullaz(p);
                fajlbeolv60x15(p);
                break;
            case menube :
                printf("\n --- Vissza a menube --- \n");
                break;
            }
        break;
        case start :
            printf("Szimulacio inditasa:\n");
            printf("0 - A szimulacio automatikus futtatasahoz.\n"
                   "1 - A szimulacio lepteteses futtatasahoz.\n");
            scanf("%d", &d);
            if (d == 1) {
                printf("Barmelyik egesz szam es egy enter lenyomasara tudsz leptetni.\n");
                printf("A 0 lenyomasaval tudsz kilepni a ciklusbol.\n");
                ism = 0;
                while (d != 0) {
                    leptet(p, q);
                    scanf("%d", &d);
                }
            } else {
                ism= 0;
                osszegint = 0;
                szorzatint = 0;
                round(p, q, ism, osszegint, szorzatint);
            }
            for(i=0; i < p->meret.y; i++) {
                for (j=0; j < p->meret.x; j++) {
                    printf("%d", p->palya[i][j] );
            }
            printf("\n");
            }
            printf("\n");
            printf("\n\n --- %d --- \n", ism);
            //printf("\n\n --- %d --- \n", korszamlalo);
            felsz(p);
                break;
        case kilepes :
            printf("That's all folks!");
            break;
        }
        if (r != 4) {
            printf("\nHogyan tovabb?\n"
                   "0 - Jatekter meretenek megadasa\n"
                   "1 - Kezdo koordinatak megadasa\n"
                   "2 - Kezdo allapot betoltese fajlbol\n"
                   "3 - Szimulacio inditasa...\n"
                   "4 - Kilepes...\n");
        }
    }
}
