#ifndef AVL_H
#define AVL_H
#include "main.h"

typedef struct{
    char* cle;
    unsigned long valeur;
}Dictionnaire;

typedef enum {
    SOURCE,
    USINE,
    STORAGE,
    JUNCTION,
    SERVICE,
    USER
} NodeType;

typedef struct Node {
    char *id;
    NodeType type;
} Node;

typedef struct _troncon {
    char *id;
    
} Troncon;


typedef struct{
    char* id;
    Troncon *sources;
    Troncon *stockage;
    double capacite;
    double v_traite;
    double v_capte;
} Usine;

typedef Usine* pUsine;

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