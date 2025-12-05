#ifndef AVL_H
#define AVL_H
#include "main.h"

typedef struct{
    char* cle;
    unsigned long valeur;
}Dictionnaire;

typedef struct{
    char* id;
    double capacite;
    double v_traite;
    double v_capte;
} Usine;

typedef Usine* pUsine;

typedef struct _troncons{
    pUsine usine;
    char* id_amont;
    char *id_aval;
    double volume;
    float fuite;
}Troncons;

typedef struct AVL {
    pUsine usine;
    int eq;
    struct AVL* fd;
    struct AVL* fg;
} AVL;

typedef struct AVL* pAVL;   
/*
typedef struct {
    char* id;
    char* 
}
*/


#endif