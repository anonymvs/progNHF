#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED


// menüt vezérlõ enum
typedef enum menu_item {
    meret,
    kezdo,
    betolt,
    start,
    kilepes
} menu_item;

// elemek koordinátái
typedef struct koord {
    int x,y;
} koord ;

// a terület alapján létrehoz egy kétdimenziós dinamikus tömböt
typedef struct palya {
    koord meret;
    int **palya;
} palya;

typedef struct cells {
    int state; //két állás 1 meghal 0 él
    int meret;
    koord *pointer;
} cells;

void nullaz ( palya *p );
void foglal ( palya *p);
void megad (palya *p);
void sejtek ( palya *p, cells *q);
void die ( palya *p, cells *q);
int test ( palya *p, cells *q, int i);
void felsz_cella(cells *p);
void felsz(palya *p);

void menu( palya *p, cells *q );

#endif // HEADER_H_INCLUDED
