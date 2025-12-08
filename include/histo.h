#ifndef HISTO_H
#define HISTO_H

#include "main.h"

typedef struct _token_liste{
    char token[256];
    struct _token_liste* suivant;
}Token_liste;

void recuperersource(char* sauvegarde[5], char* ligne);
pAVL ajouterAVLUsine(pAVL avl,pUsine usine);
char* extraireID(const char* token);

#endif