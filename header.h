#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

extern int ism;
extern int osszegint;
extern int szorzatint;
extern int korszamlalo;

// menüt vezérlõ enum
typedef enum menu_item {
    meret,
    kezdo,
    betolt,
    start,
    kilepes
} menu_item;

// Egy almenüt vezérlő enum
typedef enum menu_betolt {
    elso,
    masodik,
    harmadik,
    menube
} menu_betolt;

// elemek koordinátái
typedef struct koord {
    int x, y, state;
} koord ;

// a terület alapján létrehoz egy kétdimenziós dinamikus tömböt
typedef struct palya {
    koord meret;
    int **palya;
} palya;

// A pályán levő sejtek koordinátáit tárolja egy listában.
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
void round( palya *p, cells *q, int ism, int osszegint, int szorzatint);
void state ( palya *p, cells *q);
void verdun (palya *p, cells *q, int n);
int db (palya *p);
void leptet(palya *p, cells *q);
int osszeg(palya *p);
int szorzat(palya *p);
void randomkoord(palya *p, int top);
void koordbeir(palya*p, koord *q, int meret);
void fajlbair(palya *p, cells *q);
void fajlbeolv10x10(palya *p);
void fajlbeolv20x20 (palya *p);
void fajlbeolv60x15 (palya *p);


void menu( palya *p, cells *q );

#endif // HEADER_H_INCLUDED
