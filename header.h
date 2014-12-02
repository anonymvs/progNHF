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
    int x, y, state;
} koord ;

// a terület alapján létrehoz egy kétdimenziós dinamikus tömböt
typedef struct palya {
    koord meret;
    int **palya;
} palya;

typedef struct cells {
    int meret;
    koord *pointer;
} cells;

void nullaz ( palya *p );
void foglal ( palya *p);
void megad (palya *p);
void sejtek ( palya *p, cells *q);
void die ( palya *p, cells *q);
int test_death ( palya *p, cells *q, int i);
int test_born ( palya *p, int i, int j);
void felsz_cella(cells *p);
void felsz(palya *p);
void round( palya *p, cells *q);
void state ( palya *p, cells *q);
void verdun (palya *p, cells *q, int n);
int db (palya *p);


void menu( palya *p, cells *q );

#endif // HEADER_H_INCLUDED
