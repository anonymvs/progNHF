#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main()
{
    int i, j;
    palya eletter;
    cells sejt;
    int korszamlalo=1;
    menu(&eletter, &sejt);
    /*
    for (i=0; i<eletter.meret.y; i++) {
        for (j=0; j<eletter.meret.x; j++) {
            printf(" %d ", eletter.palya[i][j]);
        }
        printf("\n");
    }
    */
    felsz(&eletter);
    printf("Felszabaditva");
    return 0;
}
