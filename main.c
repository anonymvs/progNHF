#include <stdio.h>
#include <stdlib.h>
#include "header.h"

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
