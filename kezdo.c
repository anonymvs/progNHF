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
