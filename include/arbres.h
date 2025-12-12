#ifndef AVL_H
#define AVL_H
#include "main.h"

typedef struct{
    char* id;
    unsigned long capacite;
    unsigned long v_traite;
    unsigned long v_capte;
} Usine;

typedef Usine* pUsine;

typedef struct AVL {
    pUsine usine;
    int eq;
    struct AVL* fd;
    struct AVL* fg;
} AVL;

typedef struct AVL* pAVL;  

typedef struct {
    //char id[64];
    //unsigned long valeur;
    pUsine usine;
}Dictionnaire;


//fonction

pAVL insertionAVL(pAVL a, pUsine usine, int *h);
void libererAVL(pAVL a);
int recherche_i(pAVL a, char* id);
pAVL recherche(pAVL a, const char* id);
void afficherAVL(pAVL avl, int* cmp);
#endif